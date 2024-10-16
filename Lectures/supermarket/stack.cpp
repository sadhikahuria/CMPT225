#include <iostream>
#include "stack.h"


MyStack::MyStack(): top {nullptr}, count {0}{};
MyStack::~MyStack(){
    if (top != nullptr){
        Node *temp = top;
        if (top != nullptr){
            top = top-> next;
            delete temp -> val;
            delete temp;
            temp = top;
        }
    }
}

MyStack::MyStack(const MyStack& other): top {nullptr}, count {0}{
    if (other.top != nullptr){

        top = new Node();
        Apple *copy_apple = new Apple();
        top -> val = copy_apple;
        copy_apple -> id = other.top -> val -> id;
        copy_apple -> sold = other.top -> val -> sold;

        Node *currentother = other.top -> next;
        Node *current = top;
        
        
        while (currentother != nullptr){
            Node *newnode = new Node();
            Apple *newapple = new Apple();
            newnode -> val = newapple;
            newapple -> id = currentother -> val -> id;
            newapple -> sold = currentother -> val -> sold;
            current-> next = newnode;
            current = current -> next;
            currentother = currentother -> next;
            count++; 
        }
        current -> next = nullptr;

    }

}

void MyStack::push( Apple * newval){

    Node *newnode {new Node()};
    newnode -> val = newval;
    newnode -> next = top;
    top = newnode;
}

Apple* MyStack::pop(){
    if (top != nullptr){
        Node *temp = top;
        Apple *returnval = top -> val;
        top -> val -> sold = true;
        top = top -> next;
        delete temp;
        return returnval;
    }
}

int MyStack::size(){ 
    return count;
}

void MyStack::print(){
    if (top != nullptr){
        Node *current = top;
        while (current != nullptr){
            bool status = current -> val -> sold;
            
            std::cout << "Apple " << current -> val -> id;
            if(status){
                std::cout << " sold" << std::endl;
            }
            else {
                std::cout << " Not sold" << std::endl;
            }
            current = current -> next;
        }
    }
}
