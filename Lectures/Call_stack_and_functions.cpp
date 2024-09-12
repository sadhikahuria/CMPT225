#include <iostream>
using namespace std;

double power(double x, int exp){
    double result = 1;
    for (int i = 1; i <= exp; i++){
        result *= x;

    }
    return result;

}
void squareArray(double a[], int n){
    for (int i = 0; i < n; i++){
        int x = a[i];
        a[i] = power (x, 2);
    }
}

double sumArray(double a[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];

    }
    return sum;

}
int main(){
    int n = 2;
    double arr[] = {5, 17};
    squareArray(arr, n);
    int sum = sumArray(arr, n); // doesn't have to be a double because c++ converts double to int here.  
    cout << sum<< endl;
    return 0;

}


//STACKS
    // PUSH - insert an item at the top of the stack
    // POP - remove and return the top item
    // PEEK - return the top item
    // the order is based on the order the items arrive
    
