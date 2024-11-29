// YOUTUBE VIDEO: C++ Table Implementation - Coding Jesus
// https://www.youtube.com/watch?v=2_3fR-k-LzI 



// Seperate chaining
// using limited lest


#include <iostream>
#include <list>
#include <cstring>

using std::cout;
using std::string;
using std::endl;
using std::list;
using std::pair;


/*
PROMPT:
    Hashtable to implement: phonebook; 905, jimmy
*/


class HashTable{
    private:
        //how many lists we are going to use
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // list 1, index 0 , list 2, index 1...
            // pair: int and string.    pair: number and name
    public:
        bool isEmpty() const;
        int HashFunction(int key);      //take key and convert to int
        void insert(int key, string value);
        void remove(int key);
        string search(int key) const;
        void printTable() const;
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }
    if(!sum){       // sum = 0 means false, !0 means true, if !0 return true
        return true;
    } 
    return false;
}


int HashTable::HashFunction(int key){
    //We want the value of the integer to be between 0 and 9 
    return key%hashGroups;      //Key:905, int:5
}

void HashTable::insert(int key, string value){
    int hashval{HashFunction(key)};
    auto& cell {table[hashval]}; //auto lets the compiler figure out what the variable type i
    //in this case, it is a linked list with a pair of int and string
    // refrence is important as linked list is connected by pointers. 
    // cell has memory location of tht list
    auto bItr{begin(cell)};     //iterator
    bool keyExists{false};
    for(; bItr != end(cell); bItr++){
        if (bItr->first = key) // first is key. second is value etc
        {
            keyExists = true;
            bItr-> second = value;
            //replacing the value
            cout<< "[WARNING] key exists and the value has been replaced." << endl;
            break;
        }

    }

    if (!keyExists){ // if key doesn't exist
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::remove(int key){
    int hashval {HashFunction(key)};
    auto& cell {table[hashval]};
    bool keyExists{false};
    if (cell.size() != 0){
        auto Itr{cell.begin()};
        for (; Itr != cell.end(); Itr++){
            if (Itr-> first == key){
                keyExists = true;
                Itr = cell.erase(Itr);
                cout << "[INFO] Item removed"<< endl;
            }
        }
    }
    if (!keyExists){
        cout << "[WARNING] Key not found" << endl;
    }
    return;
}


void HashTable::printTable() const{
    for (int i{}; i < hashGroups; i++){
        if (table[i].size() != 0){
            auto Itr{table[i].begin()};
            for(; Itr != table[i].end(); Itr++){
                cout << "Key: " << Itr->first << "\tValue: " << Itr->second << endl;

            }
        }
    }
    return;
}


int main(){
    HashTable HT;
    
    if (HT.isEmpty()){
        cout << "Correct answer. hashtable is empty" << endl;
    }
    else {
        cout << "WRONG. check isempty function";
    }

    HT.insert(1376, "Thirteen");
    HT.insert(3466, "Thirty four");
    HT.insert(1222, "one triple two");
    HT.insert(1255, "one two double five");
    HT.insert(1213, "tweleve thirteen");
    HT.insert(147, "one fourty seven");
    HT.insert(1126, "eleven twenty six");
    HT.insert(1439, "fourteen thirty nine");
    HT.insert(340, "three fourty");
    HT.insert(1376, "replaced thirteen");


    HT.printTable();

    HT.remove(340);
    HT.remove(244);

    if (!HT.isEmpty()){
        cout << "Correct answer. hashtable is not empty" << endl;
    }
    else {
        cout << "WRONG. check isempty function";
    }

    return 0;
}
