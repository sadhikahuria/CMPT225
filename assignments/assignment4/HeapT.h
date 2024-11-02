#ifndef HEAP_T
#define HEAP_T

#include <iostream>>

/* 
does size refer to the size allocated by the array, or num
of items in the array
*/


class HeapT
{
    private:
        int *arr{nullptr};
        unsigned int capacity{};
        unsigned int count{};
        int *root{arr};
        void bubbleup(int index);
        void bubbledown(int index);

    public:
        HeapT(int val): arr{new int{val}}, capacity{val} {};
        int min(){return *root;}
        ~HeapT();
        /*overload assignment operator
            deep copies, deallocates dynamic memory 
            */
        void insert(int);
        int remove();   // throw a runtime error
        int peek();     // throw a runtime error
        HeapT& merge(const HeapT&);
        int size();


    
};

#endif
