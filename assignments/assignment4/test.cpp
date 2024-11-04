#include <iostream>
#include <stdexcept>
#include "HeapT.h"
#include "largestm.h"

using std::vector;
using std::cout;
using std::endl;

void simpleTest()
{
    // Int Heap Tests
    HeapT<int> pq1(4);

    pq1.insert(3);
    pq1.insert(1);
    pq1.insert(42);

    int peek = pq1.peek();
    cout << "pq1 root = " << peek << endl; //1
    int urgent = pq1.remove();
    cout << "pq1 root = " << pq1.peek() << endl; //3
    cout << "pq1 size = " << pq1.size() << endl; //2

    HeapT<int> pq2(pq1);
    pq2.insert(-42);
    HeapT<int> pq3 = pq1.merge(pq2); // should contain duplicates
    cout << "pq3 size = " << pq3.size() << endl; //5
    cout << "pq3 root = " << pq3.peek() << endl; //-42

    // largestm test (comment out if just testing HeapT)
    vector<int> v = { 7, 11, 3 };
    vector<int> maxm = largestm<int>(v, 1);
}

int main(){
    simpleTest();
    return 0;
}
