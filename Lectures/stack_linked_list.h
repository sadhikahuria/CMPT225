#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

class Node 
{
    public:
        int val;
        Node* next;
        Node(int newval);

};

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void push( int val );
        int pop();
        int size();
        void print();

    private:
        Node *top;
        int current_size;
};

#endif
