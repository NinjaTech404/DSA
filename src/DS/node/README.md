# Node Template Class - A Comprehensive Node Implementation for Data Structures

A robust, production-ready C++ template class for creating and managing nodes in various data structures like trees, linked lists, and graphs. This implementation provides comprehensive memory management, exception handling, and both copy and move semantics.

## 📋 Features

- **Generic Template Design**: Works with any data type
- **Comprehensive Constructors**: 12 different constructors for maximum flexibility
- **Memory Tracking**: Built-in instance counting for debugging and monitoring
- **Exception Handling**: Custom exception class with detailed error codes
- **Move Semantics**: Full support for modern C++ move operations
- **Method Chaining**: Setters return references for fluent interfaces
- **Type Safety**: Const-correct getters and setters
- **Operator Overloading**: Complete set of comparison and assignment operators

## 🚀 Quick Start

### Prerequisites
- C++17 or later compiler
- Standard Template Library (STL)

### Installation

1. Download `node.hpp` and `node.cpp`
2. Include the header in your source file:
```cpp
#include "node.hpp"
```

```fish
# 📁 Project Structure

```
├── examples/
│   └── demo.cpp
├── node.cpp
├── node.hpp
└── README.md
```

### Basic Usage

```cpp
#include <iostream>
#include <string>
#include "node.hpp"

int main() {
    // Create simple nodes
    Node<int> n1(42);
    Node<int> n2(17);
    Node<std::string> s1("Hello");
    
    // Create nodes with children (copy semantics)
    Node<int> parent(100, n1, n2);
    
    // Create nodes with children (move semantics)
    Node<int> root(50, Node<int>(25), Node<int>(75));
    
    // Method chaining
    Node<int> node;
    node.setData(10)
        .setLeft(Node<int>(5))
        .setRight(Node<int>(15));
    
    // Access children (with exception handling)
    try {
        std::cout << "Left child: " << node.getLeft().getData() << std::endl;
    } catch (const Node<int>::NodeExcept& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Track node instances
    std::cout << "Total nodes alive: " << Node<int>::total() << std::endl;
    
    return 0;
}
```

## 📚 API Reference

### Class Template: `Node<T>`

#### Static Members

| Member | Description |
|--------|-------------|
| `static size_t TOTAL` | Counter for alive node instances |
| `static size_t total()` | Returns the current node count |

#### Exception Class: `Node<T>::NodeExcept`

| Method | Description |
|--------|-------------|
| `NodeExcept(const char*)` | Constructor with custom message |
| `NodeExcept(size_t)` | Constructor with error code |
| `const char* what() const` | Returns error message |

#### Error Codes

| Code | Value | Description |
|------|-------|-------------|
| `NULLNODE` | 0xEE | Operation on null/empty node |
| `NOTANODE` | 0xFF | Invalid node operation |
| `NONODE` | 0xDD | Non-existent node access |

#### Constructors

```cpp
// Basic constructors
Node();                             // Default
Node(T data);                       // With data only

// Constructors with children (copy semantics)
Node(const lvalue left, const lvalue right);  // Both children by reference
Node(T data, const lvalue left, const lvalue right);  // With data

// Constructors with children (move semantics)
Node(rvalue left, rvalue right);                // Both children moved
Node(T data, rvalue left, rvalue right);        // With data

// Mixed semantics constructors
Node(const lvalue left, rvalue right);          // Copy left, move right
Node(rvalue left, const lvalue right);          // Move left, copy right
Node(T data, const lvalue left, rvalue right);  // With data
Node(T data, rvalue left, const lvalue right);  // With data

// Copy/Move constructors
Node(const lvalue other);    // Copy constructor
Node(rvalue other);          // Move constructor
```

#### Assignment Operators

```cpp
Node<T>& operator=(const lvalue other);  // Copy assignment
Node<T>& operator=(rvalue other);        // Move assignment
Node<T>& operator=(T data);               // Data assignment
```

#### Comparison Operators (Friend Functions)

```cpp
bool operator==(const Node<T>& first, const Node<T>& second);
bool operator!=(const Node<T>& first, const Node<T>& second);
```

#### Stream Output Operator

```cpp
std::ostream& operator<<(std::ostream& os, Node<T> node);
```

#### Member Functions

##### Setters (Support Method Chaining)

```cpp
Node<T>& setData(T data);                    // Set node data
Node<T>& setLeft(lvalue left);                // Set left child (copy)
Node<T>& setLeft(rvalue left);                // Set left child (move)
Node<T>& setRight(lvalue right);              // Set right child (copy)
Node<T>& setRight(rvalue right);              // Set right child (move)
Node<T>& setNodes(lvalue left, lvalue right); // Both children (copy)
Node<T>& setNodes(rvalue left, rvalue right); // Both children (move)
Node<T>& setNodes(rvalue left, lvalue right); // Mixed semantics
Node<T>& setNodes(lvalue left, rvalue right); // Mixed semantics
```

##### Getters

```cpp
const T& getData() const;                     // Get data (const)
Node<T>& getLeft();                            // Get left child
const Node<T>& getLeft() const;                 // Get left child (const)
Node<T>& getRight();                           // Get right child
const Node<T>& getRight() const;                // Get right child (const)
```

##### Virtual Functions

```cpp
bool isItMe(const lvalue other) const&;        // Check if same object
```

## 💡 Usage Examples

### Example 1: Binary Tree Construction
```cpp
// Build a binary tree
Node<int> leaf1(10);
Node<int> leaf2(20);
Node<int> leaf3(30);
Node<int> leaf4(40);

Node<int> internal1(15, leaf1, leaf2);
Node<int> internal2(35, leaf3, leaf4);
Node<int> root(25, internal1, internal2);
```

### Example 2: Exception Handling
```cpp
Node<int> node(100);
try {
    // This will throw because right child is null
    auto& right = node.getRight();
} catch (const Node<int>::NodeExcept& e) {
    std::cerr << "Caught: " << e.what() << std::endl;
    // Output: Caught: NONODE: the node you're invoking doesn't exist!
}
```

### Example 3: Memory Management
```cpp
{
    Node<double> n1(3.14);
    Node<double> n2(2.71);
    std::cout << Node<double>::total(); // Output: 2
    
    {
        Node<double> n3(1.61);
        std::cout << Node<double>::total(); // Output: 3
    }
    // n3 destroyed
    std::cout << Node<double>::total(); // Output: 2
}
// n1, n2 destroyed
```

### Example 4: Method Chaining
```cpp
Node<std::string> node;
node.setData("Root")
    .setLeft(Node<std::string>("Left"))
    .setRight(Node<std::string>("Right"))
    .setData("New Root");  // Chained operations
```

## 🔧 Advanced Usage

### Custom Types
```cpp
struct Person {
    std::string name;
    int age;
    
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Use with custom type
Node<Person> personNode({"Alice", 30});
```

### Linked List Implementation
```cpp
template<typename T>
class LinkedList {
    Node<T>* head;
    
public:
    void append(T data) {
        if (!head) {
            head = new Node<T>(data);
            return;
        }
        
        Node<T>* current = head;
        while (current->getRight()) {
            current = &current->getRight();
        }
        current->setRight(Node<T>(data));
    }
};
```

## ⚙️ Compilation

```bash
# Compile with C++17 support
g++ -std=c++17 -c node.cpp
g++ -std=c++17 your_program.cpp node.o -o program

# Or with all optimizations
g++ -std=c++17 -O3 -march=native node.cpp your_program.cpp -o program
```

## 🧪 Testing

```cpp
#include <cassert>

void test_node() {
    // Test basic functionality
    Node<int> n1(5);
    Node<int> n2(10);
    
    assert(n1.getData() == 5);
    assert(n2.getData() == 10);
    assert(n1 != n2);
    
    // Test copy constructor
    Node<int> n3 = n1;
    assert(n3.getData() == 5);
    
    // Test move constructor
    Node<int> n4 = std::move(n2);
    assert(n4.getData() == 10);
    
    // Test exception throwing
    try {
        n1.getLeft();
        assert(false); // Should not reach here
    } catch (const Node<int>::NodeExcept& e) {
        // Expected exception
    }
}
```

## 📊 Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Construction | O(1) | O(1) |
| Copy/Move | O(1) | O(1) |
| Getters/Setters | O(1) | O(1) |
| Exception throwing | O(1) | O(1) |

## 🔒 Thread Safety

This implementation is **not thread-safe** by default. For concurrent access, external synchronization is required:

```cpp
#include <mutex>

std::mutex node_mutex;
Node<int> shared_node;

// Thread-safe access
{
    std::lock_guard<std::mutex> lock(node_mutex);
    shared_node.setData(42);
}
```

## 🐛 Known Limitations

- No automatic memory management for child nodes (user must manage lifecycle)
- Shallow copy semantics for child pointers
- Not thread-safe without external synchronization
- Exception throwing in getters may impact performance in tight loops

## 📝 Version History

### Version 2.0.0 (2026)
- Added comprehensive move semantics
- Enhanced exception handling with error codes
- Added method chaining support
- Implemented const-correct getters
- Added static instance tracking

### Version 1.0.0 (2025)
- Initial release
- Basic node functionality
- Copy constructors
- Simple getters/setters

## 🤝 Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for:
- Bug fixes
- Performance improvements
- Documentation enhancements
- Additional features

## 📄 License

MIT License - feel free to use in personal and commercial projects.

## 👤 Author

**KADHIM SHAKIR**
- 📧 Email: kadhimshakir@yahoo.com
- 🐙 GitHub: [https://github.com/NinjaTech](https://github.com/NinjaTech)
- 📅 Created: 2026

## 🙏 Acknowledgments

- Inspired by modern C++ design patterns
- Thanks to the C++ community for best practices
- Built with robustness and reusability in mind

## 📚 See Also

- [STL Container Compatibility](#)
- [Tree Data Structure Implementation](#)
- [Graph Algorithms Using Node Class](#)
