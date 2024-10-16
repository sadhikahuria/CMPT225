#include "stack_linked_list.h"
#include <iostream>

/*
using namespace std;

Node::Node(int newval){
    val = newval;

}
LinkedList::LinkedList()
{
    top = nullptr;
    current_size = 0;
}

LinkedList::~LinkedList()
{
    Node *temp = top;
    while (top != nullptr)
    {
        top = top -> next;
        delete temp;
        temp = top;

    }
}

void LinkedList::push( int val )
{
    Node *node = new Node(val);
    node-> next = top;
    top = node;
    current_size++;
}

int LinkedList::pop(){
    int val = top-> val;
    Node *temp = top;
    top = top-> next;
    delete temp;
    current_size--;
    return val;
}

int LinkedList::size(){
    return current_size;
}

void LinkedList::print(){
    Node *temp = top;
    while(temp != nullptr){
        cout << temp->val << endl;
        temp = temp -> next;
    }
}

*/

Node::Node(int newval): val{newval}, next{nullptr}{};
LinkedList::LinkedList():top{nullptr}, current_size{0}{};

LinkedList::~LinkedList(){
    if (top != nullptr){
        Node *current = top;
        while (top != nullptr){
            top = top -> next;
            delete current;
            current = top;
        }
    }
} 


void LinkedList::push(int val){
    Node *newnode = new Node(val);
    newnode -> next = top;
    top = newnode;
    current_size++;
}

int LinkedList::pop(){
    int returnval = top -> val;
    Node *temp = top;
    top = top -> next;
    delete temp;
    temp = nullptr;
    current_size--;
    return returnval;
}

int LinkedList::size() {return current_size;}

void LinkedList::print(){
    if (top != nullptr){
        Node *current = top;
        while (current != nullptr){
            std::cout << current -> val << std::endl;
            current = current -> next;
        }
    }
}
