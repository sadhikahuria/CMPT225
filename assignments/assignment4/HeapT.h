#ifndef HEAP_T
#define HEAP_T

#include <iostream>>

/* 
does size refer to the size allocated by the array, or num
of items in the array
*/
template <typename T>

class HeapT
{
    private:
        T *arr{nullptr};
        unsigned int capacity{};
        unsigned int count{};
        const int *root{arr};
        void bubbleup(int index);
        void bubbledown(int index);

    public:
        HeapT(int val): arr{new T{val}}, capacity{val} {};

        T min(){ 
            return *root;
        }

        ~HeapT(){
            delete[] arr;
            arr = nullptr;
            root = nullptr;
        }

        /*overload assignment operator
            deep copies, deallocates dynamic memory 
            */
        
        void insert(T newval){
            if(count < capacity){
                arr[count]={newval};
                bubbleup(count);
                count++;
            }
        }

        T remove(){
            T temp = *root;
            arr[0] = arr[count-1];
            count--;
            bubbledown(0);
        }   // throw a runtime error
        
        T peek();     // throw a runtime error
        HeapT& merge(const HeapT&);
        int size();


    
};

#endif
