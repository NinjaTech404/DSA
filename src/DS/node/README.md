# Node.hpp - Generic Tree Node Implementation

A comprehensive, modern C++ template class for creating nodes in tree data structures. This header-only library provides a flexible node implementation with extensive constructor overloads, move semantics support, and various utility functions suitable for binary trees and other hierarchical data structures.

## Features

- **Modern C++ Design**: Full support for move semantics and RAII principles
- **Comprehensive Constructors**: 11 different constructor overloads for maximum flexibility
- **Exception Handling**: Built-in exception class for node-specific errors
- **Static Tracking**: Automatic counting of total nodes created in memory
- **Type Safety**: Full const-correctness and reference qualifiers
- **Method Chaining**: Setter methods return references for fluent interfaces
- **Comparison Operators**: Equality and inequality operators for node comparison
- **Stream Output**: Customizable stream output formatting

## Requirements

- C++11 or later
- Standard Template Library (STL)

## Installation

Simply include the `node.hpp` header file in your project:

```cpp
#include "node.hpp"
```

## Usage Examples

### Basic Node Creation

```cpp
#include "node.hpp"
#include <iostream>

int main() {
    // Create a node with integer data
    Node<int> n1(42);
    
    // Create nodes with string data
    Node<std::string> root("Root");
    Node<std::string> left("Left Child");
    Node<std::string> right("Right Child");
    
    // Build a tree structure
    root.setLeft(left).setRight(right);
    
    // Access data
    std::cout << "Root: " << root.getData() << std::endl;
    std::cout << "Left child: " << root.getLeft().getData() << std::endl;
    
    return 0;
}
```

### Using Different Constructors

```cpp
// Default constructor
Node<double> empty;

// Constructor with data only
Node<int> node1(100);

// Constructor with children only (copy semantics)
Node<int> left(10);
Node<int> right(20);
Node<int> parent(left, right);  // Copies left and right

// Constructor with children only (move semantics)
Node<int> parent2(std::move(left), std::move(right));  // Moves left and right

// Complete constructor with data and children
Node<int> root(50, Node<int>(25), Node<int>(75));
```

### Move Semantics and Performance

```cpp
// Efficient tree construction using move semantics
Node<std::string> buildTree() {
    return Node<std::string>(
        "Root",
        Node<std::string>("Left Branch"),
        Node<std::string>("Right Branch")
    );
}

auto tree = buildTree();  // No unnecessary copies

// Move assignment
Node<int> node1(10);
Node<int> node2(20);
node2 = std::move(node1);  // Efficient transfer of ownership
```

### Method Chaining

```cpp
Node<int> node;
node.setData(42)
    .setLeft(Node<int>(21))
    .setRight(Node<int>(84));
```

### Exception Handling

```cpp
try {
    Node<int> node;
    // Some node operations that might fail
    // The NodeExcept class can be extended for specific error handling
} catch (const Node<int>::NodeExcept& e) {
    std::cerr << "Node operation failed" << std::endl;
}
```

### Node Statistics

```cpp
// Track total nodes created
Node<int> n1(1);
Node<int> n2(2);
Node<int> n3(3);

std::cout << "Total nodes created: " << Node<int>::total() << std::endl;
// Output: Total nodes created: 3
```

### Comparison and Output

```cpp
Node<int> a(10);
Node<int> b(10);
Node<int> c(20);

if (a == b) {
    std::cout << "a and b are equal" << std::endl;
}

if (a != c) {
    std::cout << "a and c are different" << std::endl;
}

// Stream output
std::cout << "Node: " << a << std::endl;
```

## API Reference

### Constructors

| Constructor | Description |
|------------|-------------|
| `Node()` | Default constructor |
| `Node(T data)` | Creates node with data only |
| `Node(const lvalue left, const lvalue right)` | Creates node with copied children |
| `Node(rvalue left, rvalue right)` | Creates node with moved children |
| `Node(const lvalue left, rvalue right)` | Mixed reference constructor |
| `Node(rvalue left, const lvalue right)` | Mixed reference constructor |
| `Node(T data, const lvalue left, const lvalue right)` | Complete constructor with copy semantics |
| `Node(T data, rvalue left, rvalue right)` | Complete constructor with move semantics |
| `Node(T data, const lvalue left, rvalue right)` | Complete with mixed references |
| `Node(T data, rvalue left, const lvalue right)` | Complete with mixed references |
| `Node(const lvalue other)` | Copy constructor |
| `Node(rvalue other)` | Move constructor |

### Member Functions

#### Setters (all return `Node&` for chaining)

- `setData(T data)` - Set node data
- `setLeft(lvalue left)` - Set left child (copy)
- `setLeft(rvalue left)` - Set left child (move)
- `setRight(lvalue right)` - Set right child (copy)
- `setRight(rvalue right)` - Set right child (move)
- `setNodes(lvalue left, lvalue right)` - Set both children (copy)
- `setNodes(rvalue left, rvalue right)` - Set both children (move)
- Various overloads for mixed reference types

#### Getters

- `const T& getData() const` - Get const reference to data
- `Node& getLeft()` - Get reference to left child
- `const Node& getLeft() const` - Get const reference to left child
- `Node& getRight()` - Get reference to right child
- `const Node& getRight() const` - Get const reference to right child

#### Operators

- `operator=(const lvalue other)` - Copy assignment
- `operator=(rvalue other)` - Move assignment
- `operator=(T data)` - Data assignment
- `bool operator==(const Node&, const Node&)` - Equality comparison (friend)
- `bool operator!=(const Node&, const Node&)` - Inequality comparison (friend)
- `std::ostream& operator<<(std::ostream&, Node)` - Stream output (friend)

#### Virtual Functions

- `virtual bool isItMe(const lvalue other) const &` - Check node identity

#### Static Functions

- `static size_t total()` - Get total number of nodes created

## Type Aliases

- `lvalue` - Reference to `Node<T>` (`Node<T>&`)
- `rvalue` - Rvalue reference to `Node<T>` (`Node<T>&&`)

## Implementation Details

The class is designed as a header-only library with the implementation in `node.cpp` (included at the end of the header). The static member `TOTAL` tracks all node creations and destructions, providing accurate node counting across the entire program.

## Contributing

Contributions are welcome! Please feel free to submit pull requests for:
- Bug fixes
- Additional features
- Documentation improvements
- Test cases

## License

This project is open source and available under the MIT License.

## Author

**KADHIM SHAKIR**  
Email: kadhimshakir@yahoo.com

## Version History

- **1.0.0** (2026) - Initial release
  - Basic node functionality
  - Comprehensive constructor overloads
  - Move semantics support
  - Static node counting

## See Also

- [Binary Tree Implementation Examples]
- [Advanced Tree Data Structures]
- [C++ Move Semantics Guide]
