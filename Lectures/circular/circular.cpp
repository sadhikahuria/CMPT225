#include <iostream>
#include "circular.h"

List::List(): capacity{5}, front{}, count{}, arr { new int[capacity] }{};
List::List(int cal): capacity{cal}, front{}, count{}, arr { new int[capacity] }{};

List::~List(){
    delete[] arr;
}

void List::insert(int num){
    if (count < capacity){
        int pos = ((front + count) % capacity);
        arr[pos] = num;
        count++;
    }
    else {
        std::cout << "List is full" << std::endl;
    }
}


int List::remove(){
    if (count != 0){
        int temp {front};
        if (front == capacity-1){
        front = 0;
        } else {
        front++;
        }
        count--;

        return arr[temp];
    }    
}

void List::print(){
    for ( int i {}; i < count; i++){
        int pos = ((front + i ) % capacity);
        std::cout << arr[pos] << std::endl;
    }
}
