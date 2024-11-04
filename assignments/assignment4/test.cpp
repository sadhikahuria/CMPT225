#include <iostream>
#include <vector>
#include "HeapT.h"
#include "largestm.h"

void testHeapInsertAndPeek() {
    std::cout << "Test: Insert and Peek\n";

    HeapT<int> heap(5);
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    
    std::cout << "Expected peek after inserting 10, 5, 20: 5\n";
    std::cout << "Actual peek: " << heap.peek() << "\n";
    std::cout << "-------------------\n";
}

void testHeapInsertBeyondCapacity() {
    std::cout << "Test: Insert Beyond Capacity\n";

    HeapT<int> heap(3);
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);

    std::cout << "Inserting 1, 2, 3 into a heap of capacity 3\n";
    try {
        heap.insert(4);
        std::cout << "Expected exception for inserting beyond capacity\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception as expected: " << e.what() << "\n";
    }
    std::cout << "-------------------\n";
}

void testHeapRemove() {
    std::cout << "Test: Remove from Heap\n";

    HeapT<int> heap(3);
    heap.insert(15);
    heap.insert(10);
    heap.insert(5);
    
    std::cout << "Expected order of removal: 5, 10, 15\n";
    std::cout << "Remove 1: " << heap.remove() << "\n";
    std::cout << "Remove 2: " << heap.remove() << "\n";
    std::cout << "Remove 3: " << heap.remove() << "\n";

    try {
        heap.remove();
        std::cout << "Expected exception for removing from empty heap\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception as expected: " << e.what() << "\n";
    }
    std::cout << "-------------------\n";
}

void testHeapPeekEmpty() {
    std::cout << "Test: Peek on Empty Heap\n";

    HeapT<int> heap(3);
    try {
        heap.peek();
        std::cout << "Expected exception for peeking on empty heap\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception as expected: " << e.what() << "\n";
    }
    std::cout << "-------------------\n";
}

void testCopyConstructor() {
    std::cout << "Test: Copy Constructor\n";

    HeapT<int> heap(5);
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);

    HeapT<int> heapCopy(heap);
    std::cout << "Expected peek on copy: 5\n";
    std::cout << "Actual peek: " << heapCopy.peek() << "\n";
    std::cout << "Removing from original heap should not affect copy\n";
    heap.remove();
    std::cout << "Peek on copy after removing from original: " << heapCopy.peek() << "\n";
    std::cout << "-------------------\n";
}

void testAssignmentOperator() {
    std::cout << "Test: Assignment Operator\n";

    HeapT<int> heap1(5);
    heap1.insert(8);
    heap1.insert(3);
    heap1.insert(15);

    HeapT<int> heap2(3);
    heap2 = heap1;

    std::cout << "Expected peek on assigned heap2: 3\n";
    std::cout << "Actual peek: " << heap2.peek() << "\n";
    std::cout << "Removing from heap1 should not affect heap2\n";
    heap1.remove();
    std::cout << "Peek on heap2 after removing from heap1: " << heap2.peek() << "\n";
    std::cout << "-------------------\n";
}

void testMerge() {
    std::cout << "Test: Merge Heaps\n";

    HeapT<int> heap1(3);
    heap1.insert(10);
    heap1.insert(20);
    heap1.insert(5);

    HeapT<int> heap2(3);
    heap2.insert(15);
    heap2.insert(25);

    HeapT<int> mergedHeap = heap1.merge(heap2);
    std::cout << "Merged heap size: " << mergedHeap.size() << "\n";

    std::cout << "Expected order of removal from merged heap: 5, 10, 15, 20, 25\n";
    while (mergedHeap.size() > 0) {
        std::cout << "Remove: " << mergedHeap.remove() << "\n";
    }
    std::cout << "-------------------\n";
}

void testSize() {
    std::cout << "Test: Size\n";

    HeapT<int> heap(5);
    std::cout << "Expected size after creation: 0\n";
    std::cout << "Actual size: " << heap.size() << "\n";

    heap.insert(10);
    heap.insert(5);
    std::cout << "Expected size after inserting 2 elements: 2\n";
    std::cout << "Actual size: " << heap.size() << "\n";
    std::cout << "-------------------\n";
}

void testLargestM() {
    std::cout << "Test: largestm function\n";

    std::vector<int> vec = {10, 5, 2, 8, 6, 4, 3, 9, 1};
    int m = 4;
    std::vector<int> result = largestm<int>(vec, m);

    std::cout << "Expected 4 largest values in descending order: 10, 9, 8, 6\n";
    std::cout << "Actual values: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n-------------------\n";
}

void testLargestMEdgeCases() {
    std::cout << "Test: largestm Edge Cases\n";

    std::vector<int> emptyVec;
    int m = 3;
    std::vector<int> result = largestm<int>(emptyVec, m);
    std::cout << "Expected result for empty input: empty vector\n";
    std::cout << "Actual size: " << result.size() << "\n";

    std::vector<int> vec = {5, 2, 8, 6};
    m = 0;
    result = largestm<int>(vec, m);
    std::cout << "Expected result for m=0: empty vector\n";
    std::cout << "Actual size: " << result.size() << "\n";

    m = 10;
    result = largestm<int>(vec, m);
    std::cout << "Expected result for m > vector size: all elements in descending order\n";
    std::cout << "Actual values: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n-------------------\n";
}

int main() {
    testHeapInsertAndPeek();
    testHeapInsertBeyondCapacity();
    testHeapRemove();
    testHeapPeekEmpty();
    testCopyConstructor();
    testAssignmentOperator();
    testMerge();
    testSize();
    testLargestM();
    testLargestMEdgeCases();

    return 0;
}
