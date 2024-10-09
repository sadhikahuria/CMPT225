#include "StringList.h"
#include <iostream>
#include <cassert>

void testUndoSet();
void testUndoInsert();
void testUndoRemove();
void testUndoRemoveAll();
void testUndoAssignment();
void testMultipleUndoOperations();

int main() {
    std::cout << "Testing Undo Functionality...\n";
    
    testUndoSet();
    testUndoInsert();
    testUndoRemove();
    testUndoRemoveAll();
    testUndoAssignment();
    testMultipleUndoOperations();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

// Test the undo functionality for the `set` method
void testUndoSet() {
    StringList list;
    list.insertBack("apple");
    list.insertBack("banana");
    list.insertBack("cherry");

    assert(list.toString() == "{\"apple\", \"banana\", \"cherry\"}");

    list.set(1, "orange");
    assert(list.toString() == "{\"apple\", \"orange\", \"cherry\"}");

    list.undo(); // Should revert the set operation
    assert(list.toString() == "{\"apple\", \"banana\", \"cherry\"}");
    
    std::cout << "testUndoSet passed.\n";
}

// Test the undo functionality for insertion methods
void testUndoInsert() {
    StringList list;
    list.insertBack("dog");
    list.insertBack("cat");
    list.insertBack("tree");

    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.insertBefore(1, "mouse");
    assert(list.toString() == "{\"dog\", \"mouse\", \"cat\", \"tree\"}");

    list.undo(); // Should remove "mouse"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.insertFront("lion");
    assert(list.toString() == "{\"lion\", \"dog\", \"cat\", \"tree\"}");

    list.undo(); // Should remove "lion"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    std::cout << "testUndoInsert passed.\n";
}

// Test the undo functionality for the `remove` method
void testUndoRemove() {
    StringList list;
    list.insertBack("dog");
    list.insertBack("cat");
    list.insertBack("tree");

    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.remove(1); // Remove "cat"
    assert(list.toString() == "{\"dog\", \"tree\"}");

    list.undo(); // Should reinsert "cat"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    std::cout << "testUndoRemove passed.\n";
}

// Test the undo functionality for `removeAll`
void testUndoRemoveAll() {
    StringList list;
    list.insertBack("dog");
    list.insertBack("cat");
    list.insertBack("tree");

    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.removeAll();
    assert(list.toString() == "{}");

    list.undo(); // Should restore the list to its previous state
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    std::cout << "testUndoRemoveAll passed.\n";
}

// Test the undo functionality for the assignment operator
void testUndoAssignment() {
    StringList list1;
    list1.insertBack("red");
    list1.insertBack("green");
    list1.insertBack("blue");

    StringList list2;
    list2.insertBack("yellow");
    list2.insertBack("purple");

    list1 = list2;
    assert(list1.toString() == "{\"yellow\", \"purple\"}");

    list1.undo(); // Should revert back to the original "red", "green", "blue" list
    assert(list1.toString() == "{\"red\", \"green\", \"blue\"}");

    std::cout << "testUndoAssignment passed.\n";
}

// Test multiple undo operations in sequence
void testMultipleUndoOperations() {
    StringList list;
    list.insertBack("dog");
    list.insertBack("cat");
    list.insertBack("tree");
    list.insertBack("hat");

    assert(list.toString() == "{\"dog\", \"cat\", \"tree\", \"hat\"}");

    list.remove(3); // Remove "hat"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.insertBefore(1, "shoe");
    assert(list.toString() == "{\"dog\", \"shoe\", \"cat\", \"tree\"}");

    list.undo(); // Should remove "shoe"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\"}");

    list.undo(); // Should restore "hat"
    assert(list.toString() == "{\"dog\", \"cat\", \"tree\", \"hat\"}");

    std::cout << "testMultipleUndoOperations passed.\n";
}
