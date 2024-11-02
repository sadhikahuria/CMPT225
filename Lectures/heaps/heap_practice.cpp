#include <iostream>


class HEAP{
    public:
        HEAP(int newsize): arr{new int(newsize)}, size{newsize}{};
        HEAP(): arr{ new int (size)}{};
        ~HEAP(){
            delete[] arr;
        }
        void insert(int newval){
            arr[tree_count]= newval;
            bubbleup(tree_count);
            tree_count++;
        }

        int remove(){
            int temp = arr[0];
            arr[0] = arr[tree_count];
            bubbledown(0);
            tree_count--;
            return temp;

        }


    private:
        int *arr;
        int tree_count{};
        int size{10};
        
        void bubbleup(int index){
            int parent = (index -1)/2;
            if (arr[parent] <= arr[index]){
                int temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                bubbleup(parent);
            }
        }
        void bubbledown(int index){
            int leftchild = (2*index) + 1;
            int rightchild = (2 * index) +2;
            int bigger{};
            if (arr[leftchild] > arr[rightchild]){
                bigger = leftchild;
            } 
            else if ( arr[rightchild] >= arr[leftchild]){
                bigger = rightchild;
            }
            if (arr[bigger] > arr[index]){
                int temp = arr[index];
                arr[index] = arr[bigger];
                arr[bigger] = temp;
                bubbledown(bigger);
            }
        }
};
