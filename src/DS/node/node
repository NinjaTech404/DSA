/**
 * @file node.hpp
 * @brief A generic Node class implementation for tree data structures
 *
 * This template class provides a flexible node implementation suitable for
 * binary trees and other hierarchical data structures. It includes
 * comprehensive constructor overloads, move semantics support, and various
 * utility functions.
 *
 * @tparam T The type of data stored in the node
 *
 * @author KADHIM SHAKIR
 * @email kadhimshakir@yahoo.com
 * @github https://github.com/NinjaTech404
 * @date 2026
 */


#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef> // For size_t
#include <ostream> // For stream output operator
#include <string>  // For NodeExcept class usage

/**
 * @brief A generic Node class for tree structures
 *
 * This class represents a node in a tree data structure, containing data
 * and pointers to left and right child nodes. It supports modern C++ features
 * like move semantics and includes extensive constructor overloads for
 * flexible node creation.
 *
 * Features:
 * - Move semantics support for optimal performance
 * - Comprehensive constructor overloads
 * - Static tracking of total node count
 * - Exception handling through nested NodeExcept class
 * - Full setter/getter methods with both lvalue and rvalue references
 * - Comparison operators for node equality
 *
 * @tparam T The data type stored in the node
 */
template <class T> class Node {
  /* >=====> Type Definition Section <=====< */
public:
  typedef Node<T> &lvalue;  ///< Lvalue reference type alias
  typedef Node<T> &&rvalue; ///< Rvalue reference type alias

  /* >=====> SubClasses Section <=====< */
  /**
   * @brief Exception class for Node-related errors
   *
   * This nested class provides exception handling specific to Node operations.
   * Can be extended to include specific error types and messages.
   */
  class NodeExcept;

  /* >=====> Private Data Section <=====< */
private:
  T data;         ///< Data stored in the node
  Node<T> *left;  ///< Pointer to left child node
  Node<T> *right; ///< Pointer to right child node

  /* >=====> Public Section <=====< */
public:
  /* >=====> Constructors Section <=====< */

  /**
   * @brief Default constructor - Creates an empty node
   */
  Node();

  /**
   * @brief Constructor with data only
   * @param data The data to store in the node
   */
  Node(T data);

  /**
   * @brief Constructor with child nodes only (copy semantics)
   * @param left Left child node (lvalue reference)
   * @param right Right child node (lvalue reference)
   */
  Node(const lvalue left, const lvalue right);

  /**
   * @brief Constructor with child nodes only (move semantics)
   * @param left Left child node (rvalue reference)
   * @param right Right child node (rvalue reference)
   */
  Node(rvalue left, rvalue right);

  /**
   * @brief Constructor with mixed child node references (copy left, move right)
   * @param left Left child node (lvalue reference - copied)
   * @param right Right child node (rvalue reference - moved)
   */
  Node(const lvalue left, rvalue right);

  /**
   * @brief Constructor with mixed child node references (move left, copy right)
   * @param left Left child node (rvalue reference - moved)
   * @param right Right child node (lvalue reference - copied)
   */
  Node(rvalue left, const lvalue right);

  /**
   * @brief Complete constructor with data and child nodes (copy semantics)
   * @param data Data to store
   * @param left Left child node (lvalue reference - copied)
   * @param right Right child node (lvalue reference - copied)
   */
  Node(T data, const lvalue left, const lvalue right);

  /**
   * @brief Complete constructor with data and child nodes (move semantics)
   * @param data Data to store
   * @param left Left child node (rvalue reference - moved)
   * @param right Right child node (rvalue reference - moved)
   */
  Node(T data, rvalue left, rvalue right);

  /**
   * @brief Complete constructor with data and mixed child nodes (copy left,
   * move right)
   * @param data Data to store
   * @param left Left child node (lvalue reference - copied)
   * @param right Right child node (rvalue reference - moved)
   */
  Node(T data, const lvalue left, rvalue right);

  /**
   * @brief Complete constructor with data and mixed child nodes (move left,
   * copy right)
   * @param data Data to store
   * @param left Left child node (rvalue reference - moved)
   * @param right Right child node (lvalue reference - copied)
   */
  Node(T data, rvalue left, const lvalue right);

  /**
   * @brief Copy constructor
   * @param other Node to copy from
   */
  Node(const lvalue other);

  /**
   * @brief Move constructor
   * @param other Node to move from
   */
  Node(rvalue other);

  /**
   * @brief Virtual destructor
   */
  virtual ~Node();

  /* >=====> Operators Section <=====< */
  /**
   * @brief Copy assignment operator
   * @param other Node to copy from
   * @return Reference to this node
   */
  Node &operator=(const lvalue other);

  /**
   * @brief Move assignment operator
   * @param other Node to move from
   * @return Reference to this node
   */
  Node &operator=(rvalue other);

  /**
   * @brief Data assignment operator
   * @param data New data to assign to the node
   * @return Reference to this node
   */
  Node &operator=(T data);

  /* >=====> Virtual Functions Section <=====< */
  /**
   * @brief Check if the given node is the same as this node
   * @param other Node to compare with
   * @return true if it's the same node, false otherwise
   */
  virtual bool isItMe(const lvalue other) const &;

  /* >=====> Setter/Getter Section <=====< */
  /* >-----> Setter Section <-----< */
  /**
   * @brief Set node data
   * @param data New data to set
   * @return Reference to this node for method chaining
   */
  Node &setData(T data);

  /**
   * @brief Set left child node (copy semantics)
   * @param left Left child node to set
   * @return Reference to this node for method chaining
   */
  Node &setLeft(lvalue left);

  /**
   * @brief Set left child node (move semantics)
   * @param left Left child node to set
   * @return Reference to this node for method chaining
   */
  Node &setLeft(rvalue left);

  /**
   * @brief Set right child node (copy semantics)
   * @param right Right child node to set
   * @return Reference to this node for method chaining
   */
  Node &setRight(lvalue right);

  /**
   * @brief Set right child node (move semantics)
   * @param right Right child node to set
   * @return Reference to this node for method chaining
   */
  Node &setRight(rvalue right);

  /**
   * @brief Set both child nodes (copy semantics for both)
   * @param left Left child node (copied)
   * @param right Right child node (copied)
   * @return Reference to this node for method chaining
   */
  Node &setNodes(lvalue left, lvalue right);

  /**
   * @brief Set both child nodes (move semantics for both)
   * @param left Left child node (moved)
   * @param right Right child node (moved)
   * @return Reference to this node for method chaining
   */
  Node &setNodes(rvalue left, rvalue right);

  /**
   * @brief Set both child nodes (move left, copy right)
   * @param left Left child node (moved)
   * @param right Right child node (copied)
   * @return Reference to this node for method chaining
   */
  Node &setNodes(rvalue left, lvalue right);

  /**
   * @brief Set both child nodes (copy left, move right)
   * @param left Left child node (copied)
   * @param right Right child node (moved)
   * @return Reference to this node for method chaining
   */
  Node &setNodes(lvalue left, rvalue right);

  /* >-----> Getter Section <-----< */
  /**
   * @brief Get node data (const version)
   * @return Const reference to the stored data
   */
  const T &getData(void) const;

  /**
   * @brief Get left child node (non-const version)
   * @return Reference to left child node
   */
  Node &getLeft(void);

  /**
   * @brief Get left child node (const version)
   * @return Const reference to left child node
   */
  const Node &getLeft(void) const;

  /**
   * @brief Get right child node (non-const version)
   * @return Reference to right child node
   */
  Node &getRight(void);

  /**
   * @brief Get right child node (const version)
   * @return Const reference to right child node
   */
  const Node &getRight(void) const;

  /* >=====> Friend Section <=====< */
  /**
   * @brief Equality comparison operator
   * @param first First node to compare
   * @param second Second node to compare
   * @return true if nodes are equal, false otherwise
   */
  template <class OT>
  friend bool operator==(const Node<OT> &first, const Node<OT> &second);

  /**
   * @brief Inequality comparison operator
   * @param first First node to compare
   * @param second Second node to compare
   * @return true if nodes are not equal, false otherwise
   */
  template <class OT>
  friend bool operator!=(const Node<OT> &first, const Node<OT> &second);

  /**
   * @brief Stream output operator
   * @param os Output stream
   * @param node Node to output
   * @return Reference to output stream
   */
  template <class OT>
  friend std::ostream &operator<<(std::ostream &os, Node<OT> node);

  /* >=====> Static Section <=====< */
private:
  static size_t TOTAL; ///< Total number of nodes created in memory

public:
  /**
   * @brief Get total number of nodes created
   * @return Total node count
   */
  static size_t total(void);
};

#include "node.cpp" // Include the implementation file

#endif
