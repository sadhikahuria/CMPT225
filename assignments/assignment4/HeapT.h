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

        void bubbleup(unsigned int index){
            int parent = (index-1)/2;
            if ((index >= 0) && (arr[parent] > arr[index])){
                T temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                bubbleup(parent);
            }
        }

        void bubbledown(int index){
            unsigned int leftchild = (2*index) + 1;
            unsigned int rightchild = (2*index) + 2
            unsigned int small{};
            if ( leftchild < count ){
                small = leftchild;
                if ( rightchild < count){
                    if ( arr[rightchild] < arr[leftchild]){
                        small = rightchild;
                    }
                }
                if ( arr[small] > arr[index]){
                    T temp = arr[small];
                    arr[small] = arr[index];
                    arr[index] = arr[small];
                    bubbledown(small);
                }
            }
        }

    public:
        HeapT(int val): arr{new T{val}}, capacity{val} {};
        
        HeapT(const Heap& other){
            if(arr != nullptr){
                delete[] arr;
                arr = nullptr;
            }

            if(other.arr != nullptr){
                arr = new T{other.capacity};
                capacity = other.capacity;
                for(unsigned int i = 0; i < other.count; i++){
                    arr[i] = other.arr[i];
                    count++;
                }
            }
        }

        ~HeapT(){
            delete[] arr;
            arr = nullptr;
        }

        /*overload assignment operator
            deep copies, deallocates dynamic memory 
            */
        HeapT& operator=(const HeapT& other){

        }
        
        
        void insert(T newval){
            if(count < capacity){
                arr[count]={newval};
                bubbleup(count);
                count++;
            }
        }

        T remove(){
            if(root != nullptr){
                T temp {arr[0]};
                arr[0] = {arr[count-1]};
                count--;
                bubbledown(0);
            }
        }   // throw a runtime error
        
        T peek(){
            if(arr != nullptr){
                return *arr;
            }
        }    // throw a runtime error
        
        HeapT& merge(const HeapT& other);

        unsigned int size(){
            return count;
        }


    
};

#endif
