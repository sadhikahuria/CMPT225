#include <iostream>
#include "stack.h"

int main(){
    MyStack stack1;

    int apple_id_counter {0};
    int num_apples {3};

    for (int i {0}; i < num_apples; i++){
        Apple *apple {new Apple()};
        apple -> id = apple_id_counter;
        apple_id_counter++;
        stack1.push(apple);
    }

    MyStack stack2 = stack1;

}
