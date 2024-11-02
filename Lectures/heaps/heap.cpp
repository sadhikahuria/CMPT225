/*
heap ADT
heap data structure using trees

heaps are binary tree 
    two properties
    - all levels till h-1 are filled in
    - filled from left to right
    - h = log(n)

    heaps are partially ordered
    children values <= parents
    partial order
        eg
        1 - (2,3)
        1 - (3,2)
        both are heaps, values are not ordered left to right
        top of the tree has the highest priority


    heap implementation, using array
    top to bottom, left to right
    each level index
        2^(level) - 1  to  2^(level+1) - 2
    to find children index
        2i+1 and 2i+2
    to fiind parent
        (i-1)/2


    insertion (bubble up)
        if parent is bigger, swap nodes
        h comparsions
    remove (bubblw down)
        make right most leaf root
        swap with larger child
        2h comparsions
*/ 
int *arr;
void bubble_up(int i){
    int parent = ( i-1)/2;
    if ( (i>0)&&(arr[i] > arr[parent])){
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        bubble_up(parent);
    }
}
int size;
void insert(int x){
    arr[size] = x;
    bubble_up(size);
    size++;
}
/*
Heapifying data
    start from the last node' parent
    and bubble down(i) 
    then bubble down(i-1) ...
    run time O(n) insted of insert 1 at a time 
    it looks like the cost is O(nlog(n)) but its O(n)
    
Heap sort
    remove from heap array and sort it at last avaiable index
    O(n*logn)
    doesn't need additional memory


HASH TABLES
    maps, 
        key and value
        similar to dictionarys in python
            int size()
            void put(k,v)
                overwrite if same key
            bool contains(k)
            get(key)
            remove(key)
    
    rapid access



*/
