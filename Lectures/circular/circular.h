#ifndef CIRCLE
#define CIRCLE

class List{
    public:
        List();
        List(int cap);
        ~List();
        void insert(int val);
        int remove();
        void print();

    public:
        int *arr;
        int capacity;
        int front;
        int count;


};

#endif
