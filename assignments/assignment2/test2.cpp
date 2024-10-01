#include "StringList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(){
    StringList list;
    list.insertBack("Apple banana");
    list.insertFront("cherry");
    list.insertBefore(2, "orange");

    cout << endl;
    list.print();
    cout << endl;

    list.undo();
    cout << "\norange should be removed\n" << endl;
    list.print();


    list.insertFront("strawberry");
    list.insertBefore(2, "kiwi");
    list.remove(2);
    
    cout << endl;
    cout << "Next:\n";
    list.print();
    cout << endl;

    list.undo();
    cout << "\nkiwi should be added\n" << endl;
    list.print();

    list.set(1, "pos1");
    list.set(2, "pos2");
    list.insertBefore(3, "lol");

    cout << "\nNext:\n";
    list.print();
    list.undo();
    list.undo();
    list.undo();
    cout << "\npos1, pos2 should be back to cherry and kiwi, and lol shouls be removed\n";
    cout << endl;
    list.print();

    cout << "\nNext: \nRemove all operations and undoing it to retore the list\n";
    list.removeAll();
    list.print();
    list.undo();
    cout << "\nList should be same as befoere\n";
    list.print();
    cout << endl;

    cout << "\nFinal test assignment operator, List 2 is:\n";

    StringList list2;
    list2.insertBack("one");
    list2.insertBack("two");
    list2.insertBack("Three");
    list2.insertBack("Four");
    list2.insertBack("Five");
    list2.insertBack("Six");

    list2.print();
    cout << "\nAssigning list 2 to list 1. and printing list 2:\n";
    list2 = list;
    list2.print();
    cout << "\nCalling undo twice. List 2 should be retored and element 6 should be removed\n";
    list2.undo();
    list2.undo();
    cout << endl;
    list2.print();
    cout << endl;

    cout << "Last, calling undo till undo stack is empty for list2";
    list2.undo();
    list2.undo();
    list2.undo();
    list2.undo();
    list2.undo();
    // adding this should fail the excution
    //list2.undo();
    cout << endl;
    list2.print();
    return 0;
}
