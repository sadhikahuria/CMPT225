#include <iostream>
/*
Sorting        

    Assume that running time t of an alogorithm is 
    proportional to the number of operations
    
    express t as a function of n
    t(n)

    eg:
*/
        void printArray(int arr[], int n){
            for (int i = 0; i < n; ++i){
                std::cout << arr[i] << std::endl;
            }
        }
/*
        1 - intialize
        n - comparion, i< n
        n - increment ++i
        n - print
        1 - terminating comparsion, i< n

        t = 3n + 2

    barometer instruction / key operation
        the instruction is executed the greated number of times
*/
 
/*

Linear search
    Best case
        first pos - one comparison
    worst case
        last pos - n comparison
    average case
        n+1/2 position
        n+1 / size comparsion
        one average, linear search perfomrs (3n +1)/4 comparsions

    Assumptions:
        1- The target is not in the array half of the time
        2- there is an equal probability of the target being at any array location if it is in the array
    
    Probabilty is 1/n of being in ith location


*/

/*
    Linear search:
        average case time 
            all possible case time / number of cases
                1 + 2 + 3 + ... + n / n
                (n+1)/2 
    
        average if target is in array (n+1)/2
        average if target is not in the array (n)
        for average we divide by 2
        ( in array + not in array ) / 2
        ( (n+1)/2 + n ) / 2
        ( (3n + 1)/2 ) / 2
        ( 3n + 4 ) / 2 : weighted average

    */

// not recursive
int binarySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    int mid = 0; 
    while (low <= high){
        mid = (low + high) / 2;
        if ( target == arr[mid] ){
            return mid;
        }
        else if ( target > arr[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
    // t binary 5(log2(n)+1) + 4
}


/*
Simple sorting

Selection sort

Insertion sort
    working with two elements at one time to search
*/

int getSmallest( int arr[], int start, int end){
    int smallest = start;                       
    for (int i = start +1; i < end; ++i){       
        if (arr[i] < arr[smallest]){            
            smallest = i;                        
        }
    }
    return smallest;
}

void swap (int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

} 

void selectionsort(int arr[], int n){
    for (int i = 0; i < n-1; ++i){               
        int smallest = getSmallest(arr, i, n);  
        swap(arr, i, smallest);
    }
}
 
/*
Counting sequences
    i + i+1 + ... + n-1 + n
        ( (i+n)/2 ) * (n-i+1)
    
    eg 
        2 + 3 + 4 + 5 + 6
        (2+6)/2 * (6-2+1)
        8/2 * 5
        20

    eg 
        1 + 2 + 3 + ... + n-2 + n-1
        (1 + n-1)/2 * (n-1-+1)
        n/2 * n
        n^2 / 2
*/
