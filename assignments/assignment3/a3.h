#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;



//Question 1

void cartesianProduct(int arr[], int n, int &operations)
{
    int i = 0;      //this line

    operations = 1;
    
    while (i < n) {
        int j = 0;

        operations += 2;
        
        while (j < n) {
            cout << "{" << arr[i] << "," << arr[j] << "}";
            j++;
            cout << " ";
            
            operations += 4;
        }

        cout << endl;
        i++;

        operations += 3;
    }

    operations++;
}




//Question 2 

void triangle(int x, int &operations)
{
    int i = 0;

    operations = 1;

    while (i < x) {
        int j = 0;

        operations += 2;

        while (j <= i) {
            cout << j << " ";
            j++;

            operations += 3;
        }

        cout << endl;           
        i++;

        operations += 3;
    }

    while (i > 0) {
            i--;
            int j = 0;

            operations += 3;

            while (j <= i) {
                    cout << j << " ";
                    j++;

                    operations += 3;

            }
            cout << endl;

            operations += 2;
    }

    operations += 2;
}




//Question 3

int* matrixSelfMultiply(int* m, int rows, int &operations)
{
    int columns = rows;
    int* result = new int[rows * columns];
    int r = 0;

    operations = 3;

    while (r < rows) {
        int c = 0;

        operations += 2;

        while (c < columns) { //columns = rows
            int next = 0;
            int iNext = 0;

            operations += 3;

            while (iNext < rows) {
                next += m[rcIndex(r, iNext, columns, operations)] * m[rcIndex(iNext, c, columns, operations)];
                iNext++;

                operations += 3;
            }

            result[rcIndex(r, c, columns, operations)] = next;
            c++;

            operations += 3;
        }
        r++;

        operations += 2;
    }

    operations++;

    return result;
}

int rcIndex(int r, int c, int columns, int &operations)
{
    operations++;
    return r * columns + c;
}




//Question 4 

void ssort(int arr[], int n, int i, int &operations, bool first_call = true)
{
    
    if (first_call){

        operations = 0;

    }

    if (i < n-1) {
        // Find and swap smallest remaining
        int next = i + 1;
        int smallest = i;

        operations += 2;

        while (next < n) {
            if (arr[next] < arr[smallest]) {
                smallest = next;

                operations++;

            }
            next++;

            operations += 3;

        }

        // Swap i with smallest
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        ssort(arr, n, i + 1, operations, false);

        operations += 4;

    }

    operations++;

}




//Question 5 

void pattern(int n, int i, int &operations, bool first_call = true)
{
    if (first_call){
        
        operations = 0;
    }

    if (n > 0) {
        pattern(n/2, i, operations);
        cout << string(i, ' ');
        int ast = 0;

        operations += 5;

        while (ast < n) {
            cout << "* ";
            ast++;

            operations += 3;

        }

        cout << endl;
        i += n;
        pattern(n / 2, i, operations, false);

        operations += 3;
    }

    operations++;
}




//Question 6 

int lsearch(int arr[], unsigned int len, int target, int &operations, bool first_call = true) {
    
    if (first_call){
        
        operations = 0;
    }
    
    operations++;
    if (len == 0) return -1;

    operations++;
    if (arr[0] == target) return 0;

    operations++;
    if (lsearch(arr+1, len-1, target, operations, false) == -1) {
        return -1;
    } else {
        
        operations++;
        return 1 + lsearch(arr+1, len-1, target, operations, false);
    }
}




//Question 7

unsigned pow(unsigned int base, unsigned int exp, int &operations) {
    unsigned int ret = 1;

    operations = 1;

    while (exp > 0) {
        if (exp & 1) {
            ret *= base;

            operations++;

        }
        exp >>= 1; 
        base = base * base;

        operations += 4;        
    }

    operations++;

    return ret;
} 


#endif
