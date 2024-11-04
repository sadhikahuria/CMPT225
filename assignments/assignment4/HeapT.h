#ifndef HEAP_T
#define HEAP_T

#include <iostream>
#include <stdexcept>

/* 
does size refer to the size allocated by the array, or num
of items in the array
*/
template <typename T>

class HeapT
{
    private:
        T *arr{nullptr};
        int capacity{};
        int count{0};

        void bubbleup(int index){
            int parent = (index-1)/2;
            if ((index >= 0) && (arr[parent] > arr[index])){
                T temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                bubbleup(parent);
            }
        }

        void bubbledown(int index){
            int leftchild = (2*index) + 1;
            int rightchild = (2*index) + 2;
            int small{};
            if ( leftchild < count ){
                small = leftchild;
                if ( rightchild < count){
                    if ( arr[rightchild] < arr[leftchild]){
                        small = rightchild;
                    }
                }
                if ( arr[small] < arr[index]){
                    T temp = arr[small];
                    arr[small] = arr[index];
                    arr[index] = temp;
                    bubbledown(small);
                }
            }
        }

    public:
        HeapT(int val): arr{new T[val]}, capacity{val} {};
        
        HeapT(const HeapT& other): arr{new T[other.capacity]}, capacity{other.capacity}{

            for(int i = 0; i < other.count; i++){
                insert(other.arr[i]);
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
            if( this != &other){
                if(arr != nullptr){
                    delete[] arr;
                }
                arr = new T[other.capacity];
                count = 0;
                capacity = other.capacity;
                for(int i = 0; i < other.count; i++){
                    insert(other.arr[i]);
                }
            }
            return *this;    
        }
        
        
        void insert(const T& newval){
            if(count < capacity){
                arr[count]= newval;
                bubbleup(count);
                count++;
            } else{
                throw std::runtime_error("Heap is Full.\n");
            }
        }

        T remove(){
            if((arr != nullptr) && ( count > 0 )){
                T temp {arr[0]};
                count--;
                arr[0] = {arr[count]};
                bubbledown(0);
                return temp;
            } else {
                throw std::runtime_error("Heap is empty.\n");
            }
        }   // throw a runtime error
        
        T peek() const{
            if((arr != nullptr) && (count > 0)){
                return arr[0];
            } else {
                throw std::runtime_error("Heap is empty.\n");
            }
        }    // throw a runtime error
        
        HeapT merge(const HeapT& other) const
        {
            HeapT newheap( capacity + other.capacity );
    
            for(int i{0}; i < count; i++){
                newheap.insert(arr[i]);
            }
            for(int i{0}; i < other.count; i++){
                newheap.insert(other.arr[i]);
            }

            return newheap;
        }

        int size() const{
            return count;
        }

};

#endif
