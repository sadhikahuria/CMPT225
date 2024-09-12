#include <iostream>
#include <limits>
#include <sstream>
#include "stacks_array.h"

using namespace std;

int main(){

    MyStack my_stack;
    std::string input;

    cout    << "Comands:\n"
            << "push <value> : Push a value onto the stack\n"
            << "pop: Pop th etop value from the stack\n"
            << "size: Get the size of the stack\n"
            << "print: Print the content of the stack\n"
            << "exit: Ecit the program\n";
    
    while (true){
        cout << "> ";
        getline(cin, input);

        stringstream randominput(input);
        string command;
        randominput >> command;

        if (command == "push"){
            int value;
            randominput >> value;
            if (randominput.fail()){
                cout << "invalue push\n";
            }
            else{
                my_stack.push(value);
            }

        }
        else if (command == "pop"){
            int val = my_stack.pop();
            cout << val << endl;
        } else if (command == "size"){
            cout << "stack size: " << my_stack.size() << "\n";

        } else if (command == "print") {
            my_stack.print();

        } else if (command == "exit"){
            cout << "exiting\n";
            break;
        } else {
            cout << "unknown command. try again \n";
        }

    }
    return 0;
}
