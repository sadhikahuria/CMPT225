#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

//Question 1
//This function prints the Cartesian product of its input array with itself.
//      PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n)
{
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << "{" << arr[i] << "," << arr[j] << "}";
            j++;
            cout << " ";
        }

        cout << endl;
        i++;
    }
}




//Question 2 
//This function prints a triangle of numbers 
//(which doesn't look very pretty if the numbers have more than one digit).
void triangle(int x)
{
    int i = 0;

    while (i < x) {
        int j = 0;

        while (j <= i) {
            cout << j << " ";
            j++;
        }

        cout << endl;
        i++;
    }

    while (i > 0) {
            i--;
            int j = 0;
            while (j <= i) {
                    cout << j << " ";
                    j++;
            }
            cout << endl;
    }
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
int* matrixSelfMultiply(int* m, int rows)
{
       // Create result array
       int columns = rows;
       int* result = new int[rows * columns];
       int r = 0;

       while (r < rows) {
              int c = 0;
              while (c < columns) { //columns = rows
                     int next = 0;
                     int iNext = 0;

                     while (iNext < rows) {
                           next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
                           iNext++;
                     }

                     result[rcIndex(r, c, columns)] = next;
                     c++;
              }
              r++;
       }
       return result;
}

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}




//Question 4
//This function is a recursive version of selection sort.
//      PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i)
{
       if (i < n-1) {
              // Find and swap smallest remaining
              int next = i + 1;
              int smallest = i;

              while (next < n) {
                     if (arr[next] < arr[smallest]) {
                          smallest = next;
                     }
                     next++;
              }

              // Swap i with smallest
              int temp = arr[i];
              arr[i] = arr[smallest];
              arr[smallest] = temp;
              ssort(arr, n, i + 1);
       }
}




//Question 5
//This function prints a pattern.
//Notes:
//  Assume that the string constructor (string(i,' ')) has an operation count of 3
//      PRE: n is a power of 2 greater than zero.
//      PRE: Initial call should be to i = 0
//      e.g. pattern(8, 0)
void pattern(int n, int i)
{
       if (n > 0) {
              pattern(n/2, i);
              // Print i spaces
              cout << string(i, ' ');

              // A loop to print n asterisks, each one followed by a space
              int ast = 0;
              while (ast < n) {
                     cout << "* ";
                     ast++;
              }

              cout << endl;
              i += n;
              pattern(n / 2, i);
       }
}




//Question 6
//This function is a less than optimal implementation of linear search
//Notes:
//  If you are unable to find a precise, closed form, cost function then give 
//  a good upper bound. 
//      Desc: Linear search.  Reports position if found, else -1
//      Post:  Elements unchanged
int lsearch(int arr[], unsigned int len, int target) {
    if (len == 0) return -1;
    if (arr[0] == target) return 0;
    if (lsearch(arr+1, len-1, target) == -1) {
        return -1;
    } else {
        return 1 + lsearch(arr+1, len-1, target);
    }
} // lsearch




//Question 7
//This function performs exponentiation
//Notes:
//  The operation count is related to the binary representation of the exponent. If you are
//      unable to find a precise, closed form, cost function then give a good upper bound.
//  The & (bitwise AND) and >>= (right shift assignment) are bitwise operators. If you 
//      are unfamiliar with these please look them up (Google).
unsigned pow(unsigned int base, unsigned int exp) {
    unsigned int ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= base;
        }
        exp >>= 1;
        base = base * base;
    }
    return ret;
} // pow


#endif
