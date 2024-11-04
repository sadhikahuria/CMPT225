#ifndef LARGEST_M
#define LARGEST_M

#include <iostream>
#include <vector>
#include "HeapT.h"

template <typename T>

std::vector<T>  largestm(const std::vector<T>& array, int m){
    std::vector<T> return_vec;
    if( (array.size() != 0 ) && ( m > 0)){
        if(m > array.size()){
            m = array.size();
        }
        HeapT<T> myheap(m);     //cause of O(nlog(m))
        for(int i {0}; i < m; i++){
            myheap.insert(array[i]);
        }
        for (int i {m} ; i < array.size(); i++){
            if ( myheap.peek() < array[i]){
                myheap.remove();
                myheap.insert(array[i]);
            }
        }
        for(int i{0}; i < m; i++){
            return_vec.insert(return_vec.begin(), myheap.remove());
        }
    }
    return return_vec;
}
#endif

