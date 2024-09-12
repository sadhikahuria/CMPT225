#include <iostream>
#include <sstream>

using namespace std;

// only for addtion and subraction. learning sstream
int main(){
    string input;
    int val;
    int val2;
    
    getline(cin, input); // ***
    stringstream breaking(input); // ***
    string command1;
    breaking >> command1; // ***
    breaking >> val;
    string conjunction;
    breaking >> conjunction;
    breaking >> val2;

    if (conjunction == "and"){
        if (command1 == "add"){
            cout << val + val2 << endl;
        } else if (command1 == "subtract"){
            cout << val - val2 << endl;
        } else {
            cout << "wrong command" << endl;
        }
    }
    else {
        cout << "wrong conjunction" << endl;
    }

    return 0;
}
