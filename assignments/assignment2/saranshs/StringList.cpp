#include "StringList.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
using std::out_of_range;
using std::cout;
using std::endl;
using namespace std;

// Default constructor - makes an empty list of capacity 10
StringList::StringList()
{
	capacity = 10;
	n = 0;
	arr = new string[capacity];
}

// Copy constructor
StringList::StringList(const StringList& other)
{
	copyList(other);
}

// ***UNDOABLE
// Overloaded assignment operator
StringList& StringList::operator=(const StringList& other)
{
	if(&other != this)
	{
		StringList*listcopy = new StringList(*this);
		undostackk.push("RESTORE");
		undostackk.pushlist(listcopy);

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
void StringList::set(int i, string str)
{
	checkBounds(i, "set");
	string oldStr = arr[i];
	arr[i] = str;
	undostackk.push("SET" + to_string(i) + "" + oldStr);
}

// ***UNDOABLE
// Inserts the given string *before* the given index
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

	undostackk.push("REMOVE" + to_string(pos));
}

// ***UNDOABLE
// Inserts the given string at the front of the list
void StringList::insertFront(string str)
{
	checkCapacity();
	insertBefore(0, str);
	undostackk.push("REMOVE 0");
}

// ***UNDOABLE
// Inserts the given string at the back of the list
void StringList::insertBack(string str)
{
	checkCapacity();
	insertBefore(n, str);
	undostackk.push("REMOVE " + to_string(n-1));
}

// ***UNDOABLE
// Removes the element at the given index and moves elements after it down
void StringList::remove(int pos)
{
	checkBounds(pos, "remove");
	string removedstr = arr[pos];
	for (int i = pos; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
	undostackk.push("INSERT" + to_string(pos) + "" + removedstr);
}

// ***UNDOABLE
// Empties the list
void StringList::removeAll()
{
	StringList*listcopy = new StringList(*this);
	undostackk.push("RESTORE");  
	undostackk.pushlist(listcopy);
	for (int i = 0; i < n; i++) {
		arr[i] = "";
	}
	n = 0; // problem 

	
}

// Undoes the last operation that modified the list
void StringList::undo()
{
	if(undostackk.n == 0 ){
		cout<<"Nothing to undo"<< endl;
		return;
	}

	//popping the last undo
	string *commandptr = static_cast<string*>(undostackk.pop()); 
	string command = *commandptr;
	delete commandptr;

	if(command.find("SET") == 0 ){
		// this is for the set function
		int pos = stoi(command.substr(4, command.find(' ', 4)-4));
		string oldStr = command.substr(command.find(' ', 4)+1);
		arr[pos] = oldStr;
	}
	else if (command.find("REMOVE")==0){
		// this is for all the insertion function like insertbefore, insertfront and insertback to undo the insertion by removing
		int pos = stoi(command.substr(7));
		remove (pos);
	}
	else if(command.find("INSERT") == 0){
		// this is only for the remove function only not removeall
		int n1space = command.find(' ', 7);
		int pos = stoi(command.substr(7, n1space-7));
		string removedstr = command.substr(n1space +1);
		insertBefore(pos, removedstr);
	
	}
	else if(command.find("RESTORE") == 0){
		// this is for the removeall function and assingment operator 
		StringList*listcopy = static_cast<StringList*>(undostackk.pop());
		*this = *listcopy;
		delete listcopy;
	}
	// else if(command.find("RESTORE") == 0){
	// 	// this is for the removeall function
	// 	StringList*CopyList = undostackk.pop();
	// 	*this = *CopyList;
	// 	delete CopyList;
	// }
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
