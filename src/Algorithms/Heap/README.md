# Heap Sort Implementation in C++

A generic, template-based implementation of the Heap Sort algorithm featuring max heap construction and in-place sorting.

## 📋 Table of Contents
- [Overview](#overview)
- [Algorithm](#algorithm)
- [Implementation Details](#implementation-details)
- [Complexity Analysis](#complexity-analysis)
- [Usage](#usage)
- [Example](#example)
- [Features](#features)

## 🔍 Overview

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It divides its input into a sorted and an unsorted region and iteratively shrinks the unsorted region by extracting the largest element and moving it to the sorted region.

## 📊 Algorithm

The implementation consists of three main functions:

### 1. `swap(T& a, T& b)`
Utility function to exchange two elements.

### 2. `heapify(T arr[], size_t size, size_t root)`
Maintains the max heap property for a subtree rooted at given index.

### 3. `heapSort(T arr[], size_t size)`
Orchestrates the sorting process:
- Builds a max heap from the input array
- Repeatedly extracts the maximum element

## 🏗️ Implementation Details

```cpp
// Core functions:
template<class T> void swap(T& a, T& b);
template<class T> void heapify(T arr[], size_t size, size_t root);
template<class T> void heapSort(T arr[], size_t size);
```

### Heapify Process
- Compares root with its left and right children
- Swaps with the largest child if necessary
- Recursively heapifies the affected subtree

### Heap Construction
- Starts from the lowest non-leaf nodes: `size/2 - 1`
- Works bottom-up to build the max heap

## ⏱️ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Heapify | O(log n) | O(log n) - recursive call stack |
| Build Heap | O(n) | O(1) - in-place |
| Heap Sort | O(n log n) | O(1) - in-place |

## 💻 Usage

```cpp
#include <iostream>

int main() {
    // Example with integers
    int numbers[] = {12, 11, 13, 5, 6, 7};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    
    heapSort(numbers, size);
    
    // Works with any comparable type
    double decimals[] = {3.14, 2.71, 1.41, 1.73};
    heapSort(decimals, 4);
    
    return 0;
}
```

## 📝 Example

**Input:** `[12, 11, 13, 5, 6, 7]`

**Process:**
1. Build max heap: `[13, 11, 12, 5, 6, 7]`
2. Swap root with last: `[7, 11, 12, 5, 6, 13]`
3. Heapify reduced heap...
4. Continue until sorted

**Output:** `[5, 6, 7, 11, 12, 13]`

## ✨ Features

- **Generic Implementation**: Works with any data type supporting `operator>`
- **In-place Sorting**: No additional memory allocation
- **Template-based**: Compile-time polymorphism
- **Clear Documentation**: Well-commented code for educational purposes
- **Size-safe**: Uses `size_t` for array indexing

## ⚠️ Note

The implementation uses `size_t` for indices with additional bounds checking to handle unsigned integer wrap-around safely. This ensures robust behavior even with large arrays.

---

<div align="center">
  <sub>Built with ❤️ for efficient sorting</sub>
</div>
