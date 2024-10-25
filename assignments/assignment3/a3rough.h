#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



//Question 1
//This function prints the Cartesian product of its input array with itself.
//      PARAM: arr is array to print the Cartesian product of, n is size of arr
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
//This function prints a triangle of numbers 
//(which doesn't look very pretty if the numbers have more than one digit).
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

        cout << endl;           //does this count
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
//This function returns an array in dynamic memory that represents the matrix 
//that is the result of multiplying the matrix (array) parameter by itself.
//Notes:
//  The input size is the number of rows of the matrix
//  Note that the rcIndex function only contains a return statement
//      PRE: m represents a square matrix of size rows * rows
//      PARAM: rows represents the number of both rows and columns
//      POST: Returns a pointer to an array (matrix) of the same size as m
//      NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int &operations)
{
    // Create result array
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

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns, int &operations)
{
    operations++;
    return r * columns + c;
}




//Question 4 
//This function is a recursive version of selection sort.
//      PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i, int &operations, bool first_call = true)
{
    
    if (first_call){

        operations = 0;

    }

    if (i < n-1) {
        // Find and swap smallest remaining
        int next = i + 1;
        int smallest = i;

        operations += 3;

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
//This function prints a pattern.
//Notes:
//  Assume that the string constructor (string(i,' ')) has an operation count of 3
//      PRE: n is a power of 2 greater than zero.
//      PRE: Initial call should be to i = 0
//      e.g. pattern(8, 0)
void pattern(int n, int i, int &operations, bool first_call = true)
{
    //intialize operations
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
//This function is a less than optimal implementation of linear search
//Notes:
//  If you are unable to find a precise, closed form, cost function then give 
//  a good upper bound. 
//      Desc: Linear search.  Reports position if found, else -1
//      Post:  Elements unchanged
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
} // lsearch




//Question 7
//This function performs exponentiation
//Notes:
//  The operation count is related to the binary representation of the exponent. If you are
//      unable to find a precise, closed form, cost function then give a good upper bound.
//  The & (bitwise AND) and >>= (right shift assignment) are bitwise operators. If you 
//      are unfamiliar with these please look them up (Google).
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

        operations += 4;        //all combined
    }

    operations++;

    return ret;
} // pow


#endif
