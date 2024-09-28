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

// not recursive
int binarySearch(int arr[], int n, int x){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while (low <= high){
        mid = (low + high) / 2;
        if ( x == arr[mid] ){
            return mid;
        }
        else if ( x > arr[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


/*
Simple sorting

Selection sort

Insertion sort
    working with two elements at one time to search
*/

int getSmallest( int arr[], int start, int end){
    int smallest = start;
    for (int i = start +1; i < end; i++){
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
