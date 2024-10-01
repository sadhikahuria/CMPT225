#include "StringList.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

using std::out_of_range;
using std::cout;
using std::endl;
using namespace std;

// Default constructor - makes an empty list of capacity 10
StringList::StringList() : undostack()
{
	
	capacity = 10;
	n = 0;
	arr = new string[capacity];
}

// Copy constructor
StringList::StringList(const StringList& other) : undostack()
{
	copyList(other);
}

// ***UNDOABLE
// Overloaded assignment operator
StringList& StringList::operator=(const StringList& other)
{
	if(&other != this)
	{
		stringstream operation;
		operation << "RESTORE ";
		for ( int i = 0; i < n; i++ ){
			operation << arr[i] << " ";
		}
		operation << "END ";
		undostack.push(operation.str());


		delete[] arr;
		copyList(other);
	}
	return *this;
}

// Destructor
StringList::~StringList()
{
	delete[] arr;
}

// ACCESSORS
// Returns the number of elements in the list
int StringList::size() const
{
	return n;
}

// Returns true if the list is empty, false otherwise
bool StringList::empty() const
{
	return n == 0;
}

// Returns the string at the given index
string StringList::get(int i) const
{
	checkBounds(i, "get");
	return arr[i];
}

// Returns the index of the first occurrence of the given string
int StringList::index(string s) const
{
	int i = 0;
	while (i < n && s != arr[i]) {
		i++;
	}
	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}

// Returns true iff the given string is in the list
bool StringList::contains(string str) const
{
	return !(index(str) == -1);
}

// Returns true if the two lists are equal, false otherwise.
// Does *not* consider any undo information when comparing two Stringlists. All
// that matters is that they have the same strings in the same order.
bool StringList::operator==(const StringList& sl) const
{
	if (size() != sl.size())
	{
		return false;
	}
	for (int i = 0; i < size(); i++)
	{
		if (get(i) != sl.get(i))
		{
			return false;
		}
	}
	return true;
}

// Returns true if the two lists are not equal, false otherwise
bool StringList::operator!=(const StringList& sl) const
{
	return !(*this == sl);
}

// Returns a string representation of the list.
string StringList::toString() const
{
	string result = "{";
	for (int i = 0; i < size(); i++)
	{
		if (i > 0) {
			result += ", ";
		}
		result += "\"" + get(i) + "\"";
	}
	return result + "}";
}


// MUTATORS

	// ***UNDOABLE
	// Sets the value at the given index
			// inverse operation: set i str
	void StringList::set(int i, string str)
	{
		//pushing the inverse operation onto the undo stack
		checkBounds(i, "set");
		string oldstr = arr[i];

		arr[i] = str;

		undostack.push("SET " + std::to_string(i) + " " + oldstr);

	}

	// ***UNDOABLE
	// Inserts the given string *before* the given index
			//inverse operation:  remove i 
	void StringList::insertBefore(int pos, string str)
	{
		
		// Doesn't use checkBounds because it's okay to insert at the end
		if (pos < 0 || pos > size()) {
			throw out_of_range("StringList::insertBefore index out of bounds");
		}
		checkCapacity();
		for (int i = n; i > pos; i--) {
			arr[i] = arr[i-1];
		}
		arr[pos] = str;
		n++;

		undostack.push("REMOVE " + to_string(pos));
	}

	// ***UNDOABLE
	// Inserts the given string at the front of the list
			// remove 0, using insert before
	void StringList::insertFront(string str)
	{
		checkCapacity();
		insertBefore(0, str);
	}

	// ***UNDOABLE
	// Inserts the given string at the back of the list
			// remove n using insert before
	void StringList::insertBack(string str)
	{
		checkCapacity();
		insertBefore(n, str);
	}

	// ***UNDOABLE
	// Removes the element at the given index and moves elements after it down
			// insert pos str
	void StringList::remove(int pos)
	{
		checkBounds(pos, "remove");

		string oldstr = arr[pos]; 
		for (int i = pos; i < n; i++) {
			arr[i] = arr[i + 1];
		}
		n--;

		undostack.push("INSERT " + to_string(pos) + " " + oldstr);
	}

	// ***UNDOABLE
	// Empties the list
	void StringList::removeAll()
	{
		stringstream operation;
		operation << "RESTORE ";
		for ( int i = 0; i < n; i++ ){
			string oldstr = arr[i];
			operation << oldstr << " ";
		}
		operation << "END ";
		undostack.push(operation.str());

		for (int i = 0; i < n; i++) {
			arr[i] = "";
		}
		n = 0;
	}


	// Undoes the last operation that modified the list
	void StringList::undo()
	{
		if ( undostack.undo_top == -1 ){
			throw out_of_range("the undo stack is empty");
		}

		string operation = undostack.pop();
		stringstream ss(operation);
		string mutator;
		ss >> mutator;

		if ( mutator == "SET"){
			int pos;
			string newstr;
			ss >> pos >> newstr;
			arr[pos] = newstr;
		}
		else if ( mutator == "INSERT" ){
			int pos;
			string str;
			ss >> pos >> str;
			if (pos < 0 || pos > size()) {
				throw out_of_range("StringList::insertBefore index out of bounds");
			}
			checkCapacity();
			for (int i = n; i > pos; i--) {
				arr[i] = arr[i-1];
			}
			arr[pos] = str;
			n++;

		}
		else if (mutator == "REMOVE"){
			int pos;
			ss >> pos;

			checkBounds(pos, "remove");

			for (int i = pos; i < n; i++) {
				arr[i] = arr[i + 1];
			}
			n--;
		}
		else if (mutator == "RESTORE"){

			for (int i = 0; i < n; i++) {
				arr[i] = "";
			}
			n = 0;

			string newstr;
			while ( (ss >> newstr) && ( newstr != "END") ){
				if (n < 0 || n > size()) {
					throw out_of_range("StringList::insertBefore index out of bounds");
				}
				checkCapacity();
				for (int i = n; i > n; i--) {
					arr[i] = arr[i-1];
				}
				arr[n] = newstr;
				n++;
			}

		}

	}



// Prints the list
void StringList::print() const
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

// Helper function for checking index bounds.
void StringList::checkBounds(int i, string s) const
{
	if (i < 0 || i >= size()) {
		throw out_of_range("StringList::" + s + " index out of bounds");
	}
}

// POST: Doubles the capacity of the list if n == capacity
void StringList::checkCapacity()
{
	if (n == capacity) {
		capacity *= 2;
		string* temp = new string[capacity];
		
		for (int i = 0; i < n; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
}

// Helper function to copy the contents of another list
void StringList::copyList(const StringList& lst)
{
	capacity = lst.capacity;
	n = lst.n;
	arr = new string[capacity];

	for (int i = 0; i < n; i++) {
		arr[i] = lst.arr[i];
	}
}

// UndoStack

	StringList::UndoStack::UndoStack() : capacity{4}, undo_top{-1}
	{
		undo_arr = new string[capacity];
	}

	StringList::UndoStack::~UndoStack(){
		delete[] undo_arr;
	}

	void StringList::UndoStack::push(const string &operation){

		if (undo_top == capacity-1){
			capacity = capacity*2;
			string *temp { new string[capacity] };

			for (int i = 0; i < undo_top+1; i++){
				temp[i] = undo_arr[i];
			}

			delete[] undo_arr;
			undo_arr = temp;
		}

		undo_top++;
		undo_arr[undo_top] = {operation};

	}

	string StringList::UndoStack::pop(){
		
		if (undo_top == -1){
			throw out_of_range("The undo Stack is empty");
		}
		else {

			undo_top--;
			return undo_arr[undo_top+1];

		}
	}

	

