
#ifndef STACK_H
#define STACK_h

class Apple{
    public:
        int id;
        bool sold = false;
};

class Node{
    public:
        Apple *val;
        Node *next;
};

class MyStack{
    public:
        MyStack();
        ~MyStack();
        MyStack(const MyStack& other);
        void push( Apple * newval);
        Apple *pop();
        int size();
        void print();


    private:
        Node *top;
        unsigned int count;
};

#endif
