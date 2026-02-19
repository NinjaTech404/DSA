# DSA in C++: A Comprehensive Implementation of Data Structures and Algorithms

A professional collection of Data Structures and Algorithms implemented in C++, designed for educational purposes and practical reference. This repository aims to provide clean, well-documented implementations that demonstrate modern C++ practices and efficient algorithmic thinking.

![C++](https://img.shields.io/badge/C++-20-blue.svg)
![DSA](https://img.shields.io/badge/DSA-Complete%20Reference-green.svg)
![Build](https://img.shields.io/badge/build-CMake%20Ready-orange.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

## Table of Contents
- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Implemented Data Structures](#implemented-data-structures)
- [Implemented Algorithms](#implemented-algorithms)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Overview

This repository serves as a comprehensive reference for Data Structures and Algorithms implemented in modern C++. Each implementation emphasizes:
- **Code Clarity**: Well-documented, readable code following best practices
- **Modern C++**: Utilizing C++20 features where appropriate
- **Performance**: Efficient implementations with consideration for time and space complexity
- **Testing**: Comprehensive test coverage for reliability

## Prerequisites

### Required Software
- **CMake** (version 3.10 or higher, up to 4.1.2)
- **C++ Compiler** with C++20 support:
  - GCC 11 or higher
  - Clang 14 or higher
  - Microsoft Visual C++ 2022 or higher
- **Build System**: Make, Ninja, or equivalent

### Development Environment
- **Operating System**: Linux, macOS, or Windows (with appropriate build tools)
- **Memory**: Minimum 4GB RAM recommended
- **Storage**: 100MB free space

## Project Structure

```
DSA/
├── CMakeLists.txt          # Main CMake configuration
├── src/
│   ├── main.cpp            # Entry point and demonstration
│   ├── DS/                 # Data Structures
│   │   ├── node/           # Node implementations
│   │   ├── array/          # Array-based structures
│   │   ├── linked-list/    # Linked list implementations
│   │   ├── tree/           # Tree structures
│   │   └── graph/          # Graph implementations
│   └── algorithms/         # Algorithm implementations
│       ├── sorting/
│       ├── searching/
│       ├── dynamic/
│       └── graph/
└── tests/                  # Test suites
```

## Building the Project

### Configuration

The project uses CMake for build configuration. To set up the build environment:

```bash
# Clone the repository
git clone https://github.com/NinjaTech404/DSA.git
cd DSA

# Configure the build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build the project
cmake --build build --parallel
```

### CMake Configuration Details

The provided `CMakeLists.txt` configures:

```cmake
# Minimum CMake version required
cmake_minimum_required(VERSION 3.10...4.1.2)

# Project configuration
project(
  My_DSA_Project
  DESCRIPTION "A C++ repository for studying Data Structures and Algorithms"
  VERSION 1.0.0
  LANGUAGES CXX
)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
```

### Build Options

| Option | Description | Default |
|--------|-------------|---------|
| `CMAKE_BUILD_TYPE` | Build type (Debug/Release) | Debug |
| `BUILD_TESTING` | Enable test suite | ON |
| `ENABLE_SANITIZERS` | Enable address/UB sanitizers | OFF |

### Running the Executable

After building, execute the main program:

```bash
# Using the custom target
cmake --build build --target run

# Or directly
./build/main
```

## Implemented Data Structures

### Linear Structures
- **Dynamic Array**: Resizable array implementation with amortized analysis
- **Singly Linked List**: Forward traversal only
- **Doubly Linked List**: Bidirectional traversal
- **Circular Linked List**: Ring buffer implementation
- **Stack**: LIFO structure (array and linked list based)
- **Queue**: FIFO structure (array and linked list based)
- **Deque**: Double-ended queue

### Tree Structures
- **Binary Search Tree**: Balanced operations
- **AVL Tree**: Self-balancing BST
- **Red-Black Tree**: Color-based balancing
- **B-Tree**: Balanced tree for disk storage
- **Heap**: Priority queue implementation
- **Trie**: Prefix tree for string operations

### Graph Structures
- **Adjacency Matrix**: Dense graph representation
- **Adjacency List**: Sparse graph representation
- **Edge List**: Simple edge collection
- **Weighted Graph**: With edge weights
- **Directed/Undirected**: Both variants supported

### Hash-Based Structures
- **Hash Table**: Separate chaining implementation
- **HashMap**: Key-value store
- **HashSet**: Unique element collection

## Implemented Algorithms

### Sorting Algorithms
- **Comparison-based**: QuickSort, MergeSort, HeapSort
- **Non-comparison**: Counting Sort, Radix Sort, Bucket Sort
- **Adaptive**: Insertion Sort, Shell Sort

### Searching Algorithms
- **Linear Search**: Sequential traversal
- **Binary Search**: Divide and conquer approach
- **Interpolation Search**: For uniformly distributed data
- **Exponential Search**: For unbounded lists

### Graph Algorithms
- **Traversal**: BFS, DFS (iterative and recursive)
- **Shortest Path**: Dijkstra, Bellman-Ford, Floyd-Warshall
- **Minimum Spanning Tree**: Kruskal, Prim
- **Topological Sorting**: Kahn's algorithm, DFS-based
- **Strongly Connected Components**: Kosaraju, Tarjan

### Dynamic Programming
- **Classic Problems**: Fibonacci, Knapsack, LCS
- **Optimization**: Matrix Chain Multiplication
- **String Algorithms**: Edit Distance, Longest Palindromic Subsequence

## Testing

The project integrates with CTest for automated testing:

```bash
# Enable testing
enable_testing()

# Add tests
add_test(
  NAME MAIN_DSA_TESTS
  COMMAND $<TARGET_FILE:main>
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Run tests
ctest --output-on-failure
```

## Contributing

Contributions are welcome and appreciated. Please follow these guidelines:

1. **Fork the Repository**: Create your feature branch
2. **Code Standards**: Follow the existing code style and documentation practices
3. **Add Tests**: Ensure new functionality includes appropriate tests
4. **Update Documentation**: Maintain comprehensive documentation
5. **Submit Pull Request**: Provide clear description of changes

### Contribution Guidelines
- Use meaningful variable and function names
- Include complexity analysis in comments
- Add unit tests for new functionality
- Update README if adding major features
- Follow modern C++ best practices

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

**Repository Maintainer**: NinjaTech404

For questions, suggestions, or contributions:
- **GitHub Issues**: [Report a bug or request feature](https://github.com/NinjaTech404/DSA/issues)
- **Pull Requests**: Direct contributions via GitHub

## Acknowledgments

- Inspired by classic computer science textbooks and online resources
- Built with modern C++ practices and standards
- Tested across multiple platforms and compilers

---

*This project is maintained for educational purposes and aims to provide clear, efficient implementations of fundamental computer science concepts.*
