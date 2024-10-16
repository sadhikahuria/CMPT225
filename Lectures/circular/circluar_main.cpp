#include <iostream>
#include "circular.h"

int main(){
    List list1(5);

    while(true){
        std::cout << "enter 1 for insert\nenter 2 for remove\nenter 3 to quit" << std::endl;
        int command{};
        std::cin >> command;

        if(command == 1){
            std::cout << "enter num to insert: ";
            int newnum{};
            std::cin >> newnum;
            list1.insert(newnum);
            list1.print();
        }
        else if (command == 2){
            int val = list1.remove();
            std::cout << "removed " << val << std::endl;
        } else if (command == 3){
            break;
        }
        else {
            std::cout << "invalid"<< std::endl;
        }
    }
}
