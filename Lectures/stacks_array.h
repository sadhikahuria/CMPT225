#ifndef STACK_H
#define STACK_h

class MyStack
{
    public:
        //constructor
        MyStack();
        //destructor
        ~MyStack();

        void push(int val);
        int pop();
        int size();
        void print();


    private:
        int capacity;
        int *container;
        int top;

};


#endif
