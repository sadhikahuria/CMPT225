#include <iostream>

using namespace std;

int foos(int arr[], int i)
{
    if (i == 0) {
        return arr[i];
    }
    else {
        return arr[i] + foos(arr, i - 1);
    }
}

int main(){
    

int arr[] = { 1,2,7,3,4,3 };
cout << foos(arr, 5) << endl;


}


