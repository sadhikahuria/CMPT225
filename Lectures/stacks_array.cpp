
//STACKS
    // PUSH - insert an item at the top of the stack - constant run time
    // POP - remove and return the top item - constant run time
    // PEEK - return the top item
    // the order is based on the order the items arrive
    // Implementing
        // Arrays
        // Linked lists
    
//CLASS
    //excapsulate -enclose
    //has a data structure


#include "stacks_array.h"
#include <iostream>
#include <limits>

using namespace std;
using std::cout;
using std::endl;

MyStack::MyStack(){
    top = 0;
    capacity = 5;
    container = new int[capacity];   //allocate
}

MyStack::~MyStack(){
    delete container;     //deallcate
}

void MyStack::push(int val){
    if (top < capacity){
        container[top] = val;
        top++;
        return;
    }
    else{
        cout << "failed. array is already full\n" << endl;
        return;
    }
}

int MyStack::pop(){
    if (top > 0){
        int val = container[top - 1];
        top = top-1;
        return val;
    }
    else{
        cout << "Failed. Array is empty\n" << endl;
        return '\0';
    }
}

int MyStack::size(){
    return top;
}

void MyStack::print(){
    for(int i = top - 1; i >=0; i--){
        cout << container[i] << "\n" << endl;
    }
    return;
}


