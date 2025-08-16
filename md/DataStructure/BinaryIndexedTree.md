---
title: Binary Indexed Tree
documentation_of: ../../src/DataStructure/BinaryIndexedTree.hpp
---

# Binary Indexed Tree

Binary Indexed Tree (BIT), also known as a Fenwick Tree, is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.

## Template Parameters

- `typename T`: The type of the elements.

## Member Functions

| Function | Description | Complexity |
|:---|:---|:---|
| `BinaryIndexedTree(int n)` | Constructs a BIT of size `n`, initialized to zero. | $O(N)$ |
| `BinaryIndexedTree(int n, T a)` | Constructs a BIT of size `n`, with all elements initialized to `a`. | $O(N)$ |
| `BinaryIndexedTree(const std::vector<T>& y)` | Constructs a BIT from the elements of a vector. | $O(N)$ |
| `void add(int i, T a = 1)` | Adds `a` to the element at index `i`. | $O(\log N)$ |
| `T sum(int i)` | Calculates the sum of the range `[0, i)`. | $O(\log N)$ |
| `T sum(int l, int r)` | Calculates the sum of the range `[l, r)`. | $O(\log N)$ |
| `T operator[](int k)` | Returns the value of the element at index `k`. | $O(\log N)$ |
| `int find(T k)` | Finds the smallest index `i` such that `sum(i + 1) > k`. This is equivalent to finding the k-th element (0-indexed) if the BIT represents a frequency array. Returns -1 if no such index exists. | $O(\log N)$ |

## Usage

```cpp
// Example: Point Add Range Sum
#include <iostream>
#include "src/DataStructure/BinaryIndexedTree.hpp"

int main() {
    int N = 5;
    BinaryIndexedTree<long long> bit(N);

    // Initial array: [0, 0, 0, 0, 0]
    
    bit.add(0, 10); // Add 10 to index 0
    bit.add(2, 20); // Add 20 to index 2
    bit.add(4, 30); // Add 30 to index 4
    // Array becomes: [10, 0, 20, 0, 30]

    // Calculate sum of range [0, 3) which is 10 + 0 + 20
    std::cout << "Sum [0, 3): " << bit.sum(0, 3) << std::endl; // Output: 30

    // Calculate sum of all elements [0, 5)
    std::cout << "Sum [0, 5): " << bit.sum(0, 5) << std::endl; // Output: 60
}
```