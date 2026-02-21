/**
 * @file demo.cpp
 * @brief Demonstration program for the Node template class
 * 
 * This program showcases various features and use cases of the Node class
 * including constructors, operators, exception handling, and memory management.
 * 
 * @author KADHIM SHAKIR
 * @email kadhimshakir@yahoo.com
 * @github https://github.com/NinjaTech
 * @date 2026
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "../node.hpp"

// Helper function to print section headers
void printHeader(const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "📌 " << title << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

// Helper function to print sub-section headers
void printSubHeader(const std::string& title) {
    std::cout << "\n🔹 " << title << std::endl;
    std::cout << std::string(60, '-') << std::endl;
}

// Helper function to print node info
template<typename T>
void printNodeInfo(const std::string& label, const Node<T>& node, bool showChildren = false) {
    std::cout << std::left << std::setw(25) << label << ": " << node.getData();
    
    if (showChildren) {
        std::cout << " | Left: ";
        try {
            std::cout << node.getLeft().getData();
        } catch (...) {
            std::cout << "null";
        }
        
        std::cout << ", Right: ";
        try {
            std::cout << node.getRight().getData();
        } catch (...) {
            std::cout << "null";
        }
    }
    std::cout << std::endl;
}

// Custom struct for demonstration
struct Person {
    std::string name;
    int age;
    
    Person(const std::string& n = "", int a = 0) : name(n), age(a) {}
    
    // For equality comparison
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
    
    bool operator!=(const Person& other) const {
        return !(*this == other);
    }
};

// Overload stream operator for Person
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << "(" << p.age << ")";
    return os;
}

// Example 1: Basic Node Operations
void demoBasicOperations() {
    printHeader("EXAMPLE 1: BASIC NODE OPERATIONS");
    
    // Default constructor
    printSubHeader("Default Constructor");
    Node<int> n1;
    std::cout << "Default node created (using default data for int: " << n1.getData() << ")" << std::endl;
    
    // Constructor with data
    printSubHeader("Constructor with Data");
    Node<int> n2(42);
    Node<std::string> n3("Hello, World!");
    Node<double> n4(3.14159);
    
    printNodeInfo("Integer node", n2);
    printNodeInfo("String node", n3);
    printNodeInfo("Double node", n4);
    
    // Setters with method chaining
    printSubHeader("Method Chaining with Setters");
    Node<int> n5;
    n5.setData(100)
      .setLeft(Node<int>(50))
      .setRight(Node<int>(150));
    
    printNodeInfo("Chained node", n5, true);
}

// Example 2: Constructor Variations
void demoConstructors() {
    printHeader("EXAMPLE 2: CONSTRUCTOR VARIATIONS");
    
    // Create base nodes
    Node<int> a(10);
    Node<int> b(20);
    Node<int> c(30);
    Node<int> d(40);
    
    std::cout << "Base nodes created:" << std::endl;
    printNodeInfo("Node A", a);
    printNodeInfo("Node B", b);
    printNodeInfo("Node C", c);
    printNodeInfo("Node D", d);
    
    // Constructor with both children (copy semantics)
    printSubHeader("Constructor with Both Children (Copy)");
    Node<int> parent1(50, a, b);
    printNodeInfo("Parent1 (50 with A,B)", parent1, true);
    
    // Constructor with both children (move semantics)
    printSubHeader("Constructor with Both Children (Move)");
    Node<int> parent2(60, Node<int>(25), Node<int>(35));
    printNodeInfo("Parent2 (60 with 25,35)", parent2, true);
    
    // Constructor with mixed semantics
    printSubHeader("Constructor with Mixed Semantics");
    Node<int> parent3(70, a, Node<int>(45));  // copy a, move 45
    printNodeInfo("Parent3 (70 with A,45)", parent3, true);
    
    // Constructor with only children
    printSubHeader("Constructor with Only Children");
    Node<int> parent4(a, b);  // parent4 gets default data
    printNodeInfo("Parent4 (default data with A,B)", parent4, true);
}

// Example 3: Copy and Move Semantics
void demoCopyMove() {
    printHeader("EXAMPLE 3: COPY AND MOVE SEMANTICS");
    
    // Original node
    Node<std::string> original("Original");
    original.setLeft(Node<std::string>("Left Child"))
            .setRight(Node<std::string>("Right Child"));
    
    std::cout << "Original node created:" << std::endl;
    printNodeInfo("Original", original, true);
    std::cout << "Total nodes: " << Node<std::string>::total() << std::endl;
    
    // Copy constructor
    printSubHeader("Copy Constructor (Deep Copy)");
    Node<std::string> copy = original;  // Copy constructor
    printNodeInfo("Copy of original", copy, true);
    std::cout << "Total nodes: " << Node<std::string>::total() << std::endl;
    
    // Verify they are independent
    copy.setData("Modified Copy");
    std::cout << "\nAfter modifying copy:" << std::endl;
    printNodeInfo("Original", original, true);
    printNodeInfo("Modified copy", copy, true);
    
    // Move constructor
    printSubHeader("Move Constructor");
    Node<std::string> moved = std::move(copy);  // Move constructor
    printNodeInfo("Moved node", moved, true);
    std::cout << "Total nodes: " << Node<std::string>::total() << std::endl;
    
    // Copy assignment
    printSubHeader("Copy Assignment");
    Node<std::string> assigned("Dummy");
    assigned = original;  // Copy assignment
    printNodeInfo("After copy assignment", assigned, true);
    
    // Move assignment
    printSubHeader("Move Assignment");
    Node<std::string> moveAssigned("Temp");
    moveAssigned = std::move(assigned);  // Move assignment
    printNodeInfo("After move assignment", moveAssigned, true);
}

// Example 4: Exception Handling
void demoExceptionHandling() {
    printHeader("EXAMPLE 4: EXCEPTION HANDLING");
    
    Node<int> node(100);
    std::cout << "Created node with data: " << node.getData() << std::endl;
    std::cout << "Children are nullptr (not set)" << std::endl;
    
    // Try to access non-existent children
    printSubHeader("Accessing Non-existent Children");
    
    try {
        std::cout << "Attempting to access left child..." << std::endl;
        auto& left = node.getLeft();
        std::cout << "Left child data: " << left.getData() << std::endl;
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "✅ Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nAttempting to access right child..." << std::endl;
        auto& right = node.getRight();
        std::cout << "Right child data: " << right.getData() << std::endl;
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "✅ Caught exception: " << e.what() << std::endl;
    }
    
    // Test different error codes
    printSubHeader("Testing Different Error Codes");
    
    // Create a node with custom exception using error code
    try {
        throw Node<int>::NodeExcept(NULLNODE);
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "NULLNODE exception: " << e.what() << std::endl;
    }
    
    try {
        throw Node<int>::NodeExcept(NOTANODE);
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "NOTANODE exception: " << e.what() << std::endl;
    }
    
    try {
        throw Node<int>::NodeExcept(NONODE);
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "NONODE exception: " << e.what() << std::endl;
    }
    
    // Custom message
    try {
        throw Node<int>::NodeExcept("Custom error message for testing!");
    } catch (const Node<int>::NodeExcept& e) {
        std::cout << "Custom exception: " << e.what() << std::endl;
    }
}

// Example 5: Operators
void demoOperators() {
    printHeader("EXAMPLE 5: OPERATOR OVERLOADS");
    
    Node<int> n1(100);
    Node<int> n2(100);
    Node<int> n3(200);
    
    std::cout << "Created three nodes:" << std::endl;
    printNodeInfo("Node1", n1);
    printNodeInfo("Node2", n2);
    printNodeInfo("Node3", n3);
    
    // Equality operator
    printSubHeader("Equality Operator (==)");
    std::cout << "n1 == n2 : " << (n1 == n2 ? "true" : "false") << " (same data)" << std::endl;
    std::cout << "n1 == n3 : " << (n1 == n3 ? "true" : "false") << " (different data)" << std::endl;
    
    // Inequality operator
    printSubHeader("Inequality Operator (!=)");
    std::cout << "n1 != n2 : " << (n1 != n2 ? "true" : "false") << std::endl;
    std::cout << "n1 != n3 : " << (n1 != n3 ? "true" : "false") << std::endl;
    
    // Assignment operators
    printSubHeader("Assignment Operators");
    Node<int> n4;
    n4 = 500;  // Data assignment
    std::cout << "After n4 = 500: ";
    printNodeInfo("n4", n4);
    
    n4 = n3;  // Copy assignment
    std::cout << "After n4 = n3: ";
    printNodeInfo("n4", n4);
    
    // Stream operator
    printSubHeader("Stream Operator (<<)");
    std::cout << "Node n1 via stream operator: " << n1 << std::endl;
    std::cout << "Node n2 via stream operator: " << n2 << std::endl;
    std::cout << "Node n3 via stream operator: " << n3 << std::endl;
}

// Example 6: Custom Types
void demoCustomTypes() {
    printHeader("EXAMPLE 6: CUSTOM TYPES (PERSON STRUCT)");
    
    // Create nodes with Person objects
    Node<Person> person1(Person("Alice", 25));
    Node<Person> person2(Person("Bob", 30));
    Node<Person> person3(Person("Charlie", 35));
    
    std::cout << "Created person nodes:" << std::endl;
    printNodeInfo("Person1", person1);
    printNodeInfo("Person2", person2);
    printNodeInfo("Person3", person3);
    
    // Build a simple family tree
    printSubHeader("Simple Family Tree");
    Node<Person> family(
        Person("Parent", 50),
        person1,  // Alice as left child
        person2   // Bob as right child
    );
    
    std::cout << "Family tree root: " << family.getData() << std::endl;
    std::cout << "Left child (copy): " << family.getLeft().getData() << std::endl;
    std::cout << "Right child (copy): " << family.getRight().getData() << std::endl;
    
    // Compare persons
    printSubHeader("Person Comparison");
    std::cout << "person1 == person2? " << (person1 == person2 ? "Yes" : "No") << std::endl;
    std::cout << "person1 == person1? " << (person1 == person1 ? "Yes" : "No") << std::endl;
}

// Example 7: Building a Binary Tree
void demoBinaryTree() {
    printHeader("EXAMPLE 7: BUILDING A BINARY TREE");
    
    // Create leaf nodes
    Node<int> leaf1(10);
    Node<int> leaf2(20);
    Node<int> leaf3(30);
    Node<int> leaf4(40);
    
    std::cout << "Leaf nodes created:" << std::endl;
    printNodeInfo("Leaf1", leaf1);
    printNodeInfo("Leaf2", leaf2);
    printNodeInfo("Leaf3", leaf3);
    printNodeInfo("Leaf4", leaf4);
    
    // Create internal nodes
    printSubHeader("Building Tree Bottom-Up");
    Node<int> internal1(15, leaf1, leaf2);  // 15 with children 10 and 20
    Node<int> internal2(35, leaf3, leaf4);  // 35 with children 30 and 40
    
    std::cout << "Internal nodes created:" << std::endl;
    printNodeInfo("Internal1 (15)", internal1, true);
    printNodeInfo("Internal2 (35)", internal2, true);
    
    // Create root
    Node<int> root(25, internal1, internal2);  // 25 with children 15 and 35
    
    std::cout << "\n📊 Complete Binary Tree Structure:" << std::endl;
    std::cout << "              " << root.getData() << std::endl;
    std::cout << "            /    \\" << std::endl;
    std::cout << "           " << root.getLeft().getData() << "      " << root.getRight().getData() << std::endl;
    std::cout << "          / \\    / \\" << std::endl;
    std::cout << "         " << root.getLeft().getLeft().getData() 
              << "  " << root.getLeft().getRight().getData()
              << "  " << root.getRight().getLeft().getData()
              << "  " << root.getRight().getRight().getData() << std::endl;
}

// Example 8: Memory Management and Instance Tracking
void demoMemoryManagement() {
    printHeader("EXAMPLE 8: MEMORY MANAGEMENT & INSTANCE TRACKING");
    
    std::cout << "Initial node count: " << Node<double>::total() << std::endl;
    
    // Create nodes in a scope
    {
        printSubHeader("Creating Nodes in Scope");
        Node<double> n1(1.1);
        Node<double> n2(2.2);
        Node<double> n3(3.3);
        
        std::cout << "Created 3 nodes" << std::endl;
        std::cout << "Current node count: " << Node<double>::total() << std::endl;
        
        // Create a node with children
        Node<double> parent(0.0, n1, n2);
        std::cout << "Created parent node with children" << std::endl;
        std::cout << "Node count after parent: " << Node<double>::total() << std::endl;
        
        // isItMe function demonstration
        printSubHeader("isItMe() Function");
        std::cout << "n1.isItMe(n1)? " << (n1.isItMe(n1) ? "Yes" : "No") << std::endl;
        std::cout << "n1.isItMe(n2)? " << (n1.isItMe(n2) ? "Yes" : "No") << std::endl;
    }
    
    std::cout << "\nAfter leaving scope, nodes are destroyed" << std::endl;
    std::cout << "Final node count: " << Node<double>::total() << std::endl;
}

// Example 9: Linked List Implementation using Node
void demoLinkedList() {
    printHeader("EXAMPLE 9: SIMPLE LINKED LIST USING NODE");
    
    // Create a simple linked list: 10 -> 20 -> 30 -> 40
    Node<int> node4(40);
    Node<int> node3(30, node4, Node<int>(0));  // Using right as next pointer
    Node<int> node2(20, node3, Node<int>(0));
    Node<int> head(10, node2, Node<int>(0));
    
    std::cout << "Linked List: ";
    
    // Traverse the list (using right pointers)
    Node<int>* current = &head;
    while (current) {
        std::cout << current->getData();
        try {
            current = &current->getRight();  // Move to next node
            if (current) std::cout << " -> ";
        } catch (...) {
            current = nullptr;
        }
    }
    std::cout << " nullptr" << std::endl;
}

// Example 10: Performance with Different Types
void demoTypeVariations() {
    printHeader("EXAMPLE 10: WORKING WITH DIFFERENT DATA TYPES");
    
    // Integer nodes
    printSubHeader("Integer Nodes");
    Node<int> intNode1(100);
    Node<int> intNode2(200);
    Node<int> intNode3(intNode1, intNode2);
    std::cout << "Int node1: " << intNode1 << std::endl;
    std::cout << "Int node2: " << intNode2 << std::endl;
    std::cout << "Int node3 (parent): " << intNode3.getData() << std::endl;
    
    // Double nodes
    printSubHeader("Double Nodes");
    Node<double> doubleNode1(3.14159);
    Node<double> doubleNode2(2.71828);
    Node<double> doubleNode3(doubleNode1, doubleNode2);
    std::cout << "Double node1: " << doubleNode1 << std::endl;
    std::cout << "Double node2: " << doubleNode2 << std::endl;
    std::cout << "Double node3 (parent): " << doubleNode3.getData() << std::endl;
    
    // String nodes
    printSubHeader("String Nodes");
    Node<std::string> strNode1("Hello");
    Node<std::string> strNode2("World");
    Node<std::string> strNode3(strNode1, strNode2);
    std::cout << "String node1: " << strNode1 << std::endl;
    std::cout << "String node2: " << strNode2 << std::endl;
    std::cout << "String node3 (parent): " << strNode3.getData() << std::endl;
    
    // Character nodes
    printSubHeader("Character Nodes");
    Node<char> charNode1('A');
    Node<char> charNode2('B');
    Node<char> charNode3(charNode1, charNode2);
    std::cout << "Char node1: " << charNode1 << std::endl;
    std::cout << "Char node2: " << charNode2 << std::endl;
    std::cout << "Char node3 (parent): " << charNode3.getData() << std::endl;
}

int main() {
    std::cout << "\n" << std::string(80, '⭐') << std::endl;
    std::cout << "     NODE TEMPLATE CLASS - COMPREHENSIVE DEMONSTRATION" << std::endl;
    std::cout << std::string(80, '⭐') << std::endl;
    std::cout << "Author: KADHIM SHAKIR" << std::endl;
    std::cout << "Email: kadhimshakir@yahoo.com" << std::endl;
    std::cout << "GitHub: https://github.com/NinjaTech" << std::endl;
    std::cout << std::string(80, '⭐') << "\n" << std::endl;
    
    // Run all demonstrations
    demoBasicOperations();
    demoConstructors();
    demoCopyMove();
    demoExceptionHandling();
    demoOperators();
    demoCustomTypes();
    demoBinaryTree();
    demoMemoryManagement();
    demoLinkedList();
    demoTypeVariations();
    
    // Final statistics
    printHeader("FINAL STATISTICS");
    std::cout << "Total nodes alive at end: " << Node<int>::total() << std::endl;
    std::cout << "(Should be 0 if all nodes properly destroyed)" << std::endl;
    
    std::cout << "\n" << std::string(80, '⭐') << std::endl;
    std::cout << "     DEMONSTRATION COMPLETED SUCCESSFULLY" << std::endl;
    std::cout << std::string(80, '⭐') << "\n" << std::endl;
    
    return 0;
}
