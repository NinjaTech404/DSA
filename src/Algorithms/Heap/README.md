# Heap Sort Implementation

A comprehensive C++ template library for heap sort algorithm with both max-heap and min-heap sorting capabilities. This implementation provides generic, type-safe heap operations with efficient O(n log n) performance.

## 📋 Features

- **Generic Implementation**: Template-based design works with any data type
- **Dual Heap Support**: Both max-heap (ascending) and min-heap (descending) sorting
- **In-Place Sorting**: No additional memory allocation required
- **Namespace Protection**: All functions wrapped in `heap` namespace to prevent naming conflicts
- **C++17 Compatible**: Utilizes modern C++ features
- **Well Documented**: Clear comments explaining algorithm logic

## 🚀 Quick Start

### Prerequisites
- C++17 or later compiler
- Standard Template Library (STL)

### Installation

1. Download both `heap.hpp` and `heap.cpp` files
2. Include the header in your source file:
```cpp
#include "heap.hpp"
```

### Basic Usage

```cpp
#include <iostream>
#include "heap.hpp"

int main() {
    // Example with integer array
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = std::size(numbers);
    
    // Max-heap sort (ascending order)
    heap::heap_sort(numbers, size);
    
    std::cout << "Sorted in ascending order: ";
    for(auto num : numbers) {
        std::cout << num << " ";
    }
    // Output: 11 12 22 25 34 64 90
    
    // Reset array for min-heap example
    int values[] = {64, 34, 25, 12, 22, 11, 90};
    size = std::size(values);
    
    // Min-heap sort (descending order)
    heap::min_heap_sort(values, size);
    
    std::cout << "\nSorted in descending order: ";
    for(auto val : values) {
        std::cout << val << " ";
    }
    // Output: 90 64 34 25 22 12 11
    
    return 0;
}
```

## 📚 API Reference

### Namespace: `heap`

#### `void swap(T& a, T& b)`
Swap two elements of any type.

#### `void heapify(T arr[], size_t size, size_t root)`
Maintain max-heap property for a subtree.
- `arr[]`: Array representing the heap
- `size`: Size of the heap
- `root`: Index of the root node to heapify

#### `void heap_sort(T arr[], size_t size)`
Sort array in ascending order using max-heap.
- `arr[]`: Array to sort
- `size`: Number of elements in array

#### `void min_heapify(T arr[], size_t size, size_t root)`
Maintain min-heap property for a subtree.
- `arr[]`: Array representing the heap
- `size`: Size of the heap
- `root`: Index of the root node to heapify

#### `void min_heap_sort(T arr[], size_t size)`
Sort array in descending order using min-heap.
- `arr[]`: Array to sort
- `size`: Number of elements in array

## 🔧 Algorithm Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Heapify | O(log n) | O(1) |
| Build Heap | O(n) | O(1) |
| Heap Sort | O(n log n) | O(1) |

## 💡 How It Works

### Max-Heap Sort (Ascending)
1. **Build Max-Heap**: Rearrange array into a max-heap
2. **Sort**: Repeatedly swap root (largest) with last element and heapify reduced heap

### Min-Heap Sort (Descending)
1. **Build Min-Heap**: Rearrange array into a min-heap
2. **Sort**: Repeatedly swap root (smallest) with last element and heapify reduced heap

## 🎯 Use Cases

- **Priority Queues**: Foundation for priority queue implementations
- **Scheduling Algorithms**: Task scheduling based on priority
- **Data Stream Processing**: Maintaining running median or top-k elements
- **Graph Algorithms**: Dijkstra's shortest path, Prim's minimum spanning tree
- **Embedded Systems**: Memory-efficient in-place sorting

## ⚠️ Important Notes

- The array parameter must not be a pointer when using `std::size()` - use array reference or pass size explicitly
- Functions modify the original array in-place
- Works with any type that supports comparison operators (`>`, `<`)

## 📁 File Structure

```
heap/
├── heap.hpp          # Header file with declarations and documentation
├── heap.cpp          # Implementation file with algorithm logic
├── README.md         # This documentation
└── examples/
    └── demo.cpp      # Usage examples
```

## 🔄 Comparison with Standard Sort

| Aspect | Heap Sort | std::sort |
|--------|-----------|-----------|
| Time Complexity | O(n log n) | O(n log n) |
| Space Complexity | O(1) | O(log n) |
| Stability | Unstable | Unstable |
| Use Case | Memory-constrained | General purpose |

## 🐛 Known Limitations

- Not stable (equal elements may not preserve original order)
- Not cache-friendly compared to quicksort
- Requires explicit size parameter (no automatic array size deduction for pointers)

## 📝 License

MIT License - feel free to use in personal and commercial projects

## 👤 Author

**KADHIM SHAKIR**
- Email: kadhimshakir@yahoo.com
- GitHub: [https://github.com/NinjaTech404](https://github.com/NinjaTech404)

## 🙏 Acknowledgments

- C++ standards committee for template support
- Open source community for inspiration

## 📊 Version History

- **1.0.0** (2026)
  - Initial release
  - Max-heap and min-heap implementations
  - Template-based generic design
  - Comprehensive documentation
