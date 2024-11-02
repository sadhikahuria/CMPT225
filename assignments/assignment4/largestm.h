// NOT MY CODE

#pragma once
#include "HeapT.h"
#include <vector>

template <typename T>
std::vector<T> largestm(const std::vector<T>& vec, int m) {
    int n = vec.size();
    if (m <= 0) return {};

    HeapT<T> minHeap(m);
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            minHeap.insert(vec[i]);
        } else if (vec[i] > minHeap.peek()) {
            minHeap.remove();
            minHeap.insert(vec[i]);
        }
    }

    std::vector<T> result;
    while (minHeap.size() > 0) {
        result.push_back(minHeap.remove());
    }

    // Reverse the result to get descending order
    std::reverse(result.begin(), result.end());
    return result;
}
