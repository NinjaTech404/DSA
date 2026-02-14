/**
 * @file node.cpp
 * @brief Implementation file for the Node template class
 *
 * This file contains the implementation of all Node class methods,
 * including constructors, destructor, operators, setters/getters,
 * and the nested NodeExcept exception class.
 *
 * @tparam T The type of data stored in the node
 *
 * @author KADHIM SHAKIR
 * @email kadhimshakir@yahoo.com
 * @date 2026
 */

/* >=====> Static Section <=====< */

/**
 * @brief Static member initialization
 *
 * Initializes the TOTAL counter that tracks the number of Node instances
 * currently alive in memory. This counter is incremented in constructors
 * and decremented in the destructor.
 */
template <class T> size_t Node<T>::TOTAL = 0;

/**
 * @brief Get the total number of Node instances
 *
 * @return size_t The current count of alive Node objects
 */
template <class T> size_t Node<T>::total() { return TOTAL; }

/* >=====> ERROR_CODE Section <=====< */

/**
 * @def NULLNODE
 * @brief Error code for null/empty node operations
 */
const size_t NULLNODE = 0xEE;

/**
 * @def NOTANODE
 * @brief Error code for invalid node operations
 */
const size_t NOTANODE = 0xFF;

/**
 * @def NONODE
 * @brief Error code for non-existent node operations
 */
const size_t NONODE = 0xDD;

/* >=====> SubClass Section <=====< */

/**
 * @brief Nested exception class for Node-related errors
 *
 * Provides detailed error messages for various node operation failures.
 * Supports both custom messages and predefined error codes.
 */
template <class T> class Node<T>::NodeExcept {
  std::string message; ///< Stores the error message

public:
  /**
   * @brief Constructor with custom error message
   * @param message Custom error description
   */
  NodeExcept(const char *message) { this->message = message; }

  /**
   * @brief Constructor with predefined error code
   * @param ERROR_CODE One of NULLNODE, NOTANODE, or NONODE
   */
  NodeExcept(const size_t ERROR_CODE) {
    switch (ERROR_CODE) {
    case NONODE:
      this->message = "NONODE: the node you're invoking doesn't exist!";
      break;
    case NOTANODE:
      this->message = "NOTANODE: This is NOT a node!";
      break;
    case NULLNODE:
      this->message = "NULLNODE: the node you're invoking is EMPTY!";
      break;
    default:
      this->message = "Unknown Error Occurred!";
      break;
    }
  }

  /**
   * @brief Get the error message
   * @return const char* Null-terminated error string
   */
  const char *what() const noexcept { return this->message.c_str(); }
};

/* >=====> Constructors Section <=====< */

/**
 * @brief Default constructor
 *
 * Initializes a node with null children and increments the total node count.
 */
template <class T> Node<T>::Node() {
  left = nullptr;
  right = nullptr;
  TOTAL++;
}

/**
 * @brief Constructor with data only
 * @param data The data to store in the node
 */
template <class T> Node<T>::Node(T data) {
  this->data = data;
  left = nullptr;
  right = nullptr;
  TOTAL++;
}

/**
 * @brief Constructor with child nodes (copy semantics)
 * @param left Left child node reference (copied by pointer)
 * @param right Right child node reference (copied by pointer)
 * @note Stores pointers to existing nodes, does not create copies
 */
template <class T> Node<T>::Node(const lvalue left, const lvalue right) {
  this->left = &left;
  this->right = &right;
  TOTAL++;
}

/**
 * @brief Constructor with child nodes (move semantics)
 * @param left Left child node rvalue (will be moved)
 * @param right Right child node rvalue (will be moved)
 * @note Creates new copies of the moved nodes
 */
template <class T> Node<T>::Node(rvalue left, rvalue right) {
  this->left = new Node(left);
  this->right = new Node(right);
  TOTAL++;
}

/**
 * @brief Constructor with mixed child references (copy left, move right)
 * @param left Left child node (copied by pointer)
 * @param right Right child node (moved)
 */
template <class T> Node<T>::Node(const lvalue left, rvalue right) {
  this->left = &left;
  this->right = new Node(right);
  TOTAL++;
}

/**
 * @brief Constructor with mixed child references (move left, copy right)
 * @param left Left child node (moved)
 * @param right Right child node (copied by pointer)
 */
template <class T> Node<T>::Node(rvalue left, const lvalue right) {
  this->left = new Node(left);
  this->right = &right;
  TOTAL++;
}

/**
 * @brief Complete constructor with data and child nodes (copy semantics)
 * @param data Data to store
 * @param left Left child node (copied by pointer)
 * @param right Right child node (copied by pointer)
 */
template <class T>
Node<T>::Node(T data, const lvalue left, const lvalue right) {
  this->data = data;
  this->left = &left;
  this->right = &right;
  TOTAL++;
}

/**
 * @brief Complete constructor with data and child nodes (move semantics)
 * @param data Data to store
 * @param left Left child node (moved)
 * @param right Right child node (moved)
 */
template <class T> Node<T>::Node(T data, rvalue left, rvalue right) {
  this->data = data;
  this->left = new Node(left);
  this->right = new Node(right);
  TOTAL++;
}

/**
 * @brief Complete constructor with data and mixed child references
 * @param data Data to store
 * @param left Left child node (copied by pointer)
 * @param right Right child node (moved)
 */
template <class T> Node<T>::Node(T data, const lvalue left, rvalue right) {
  this->data = data;
  this->left = &left;
  this->right = new Node(right);
  TOTAL++;
}

/**
 * @brief Complete constructor with data and mixed child references
 * @param data Data to store
 * @param left Left child node (moved)
 * @param right Right child node (copied by pointer)
 */
template <class T> Node<T>::Node(T data, rvalue left, const lvalue right) {
  this->data = data;
  this->left = new Node(left);
  this->right = &right;
  TOTAL++;
}

/**
 * @brief Copy constructor
 * @param other Node to copy from
 * @note Performs shallow copy of child pointers
 */
template <class T> Node<T>::Node(const lvalue other) {
  this->data = other.data;
  this->left = other.left;
  this->right = other.right;
  TOTAL++;
}

/**
 * @brief Move constructor
 * @param other Node to move from
 * @note Transfers ownership of resources and clears the source node
 */
template <class T> Node<T>::Node(rvalue other) {
  // Copy data and pointers from other
  this->data = other.data;
  this->left = other.left;
  this->right = other.right;

  // Clear the source node
  other.data = T();
  other.left = nullptr;
  other.right = nullptr;
  TOTAL++;
}

/**
 * @brief Destructor
 * @note Decrements the total node count
 */
template <class T> Node<T>::~Node() { TOTAL--; }

/* >=====> Global Type Definition Section <=====< */

/**
 * @brief Type aliases for lvalue and rvalue references
 */
template <class T> using lvalue = Node<T> &;
template <class T> using rvalue = Node<T> &&;

/* >=====> Operators Section <=====< */

/**
 * @brief Copy assignment operator
 * @param other Node to copy from
 * @return Reference to this node
 */
template <class T> Node<T> &Node<T>::operator=(const lvalue other) {
  this->data = other.data;
  this->left = other.left;
  this->right = other.right;
  return *this;
}

/**
 * @brief Move assignment operator
 * @param other Node to move from
 * @return Reference to this node
 */
template <class T> Node<T> &Node<T>::operator=(rvalue other) {
  // Transfer ownership
  this->data = other.data;
  this->left = other.left;
  this->right = other.right;

  // Clear the source node
  other.data = T();
  other.left = nullptr;
  other.right = nullptr;
  return *this;
}

/**
 * @brief Data assignment operator
 * @param data New data to assign
 * @return Reference to this node
 */
template <class T> Node<T> &Node<T>::operator=(T data) {
  this->data = data;
  return *this;
}

/* >=====> Virtual Functions Section <=====< */

/**
 * @brief Check if the given node is the same as this node
 * @param other Node to compare with
 * @return true if it's the same object (same memory address)
 */
template <class T> bool Node<T>::isItMe(const lvalue other) const & {
  return this == &other;
}

/* >=====> Setter/Getter Section <=====< */
/* >-----> Setter Section <-----< */

/**
 * @brief Set node data
 * @param data New data to store
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setData(T data) {
  this->data = data;
  return *this;
}

/**
 * @brief Set left child (copy semantics)
 * @param left Left child node reference
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setLeft(lvalue left) {
  this->left = &left;
  return *this;
}

/**
 * @brief Set left child (move semantics)
 * @param left Left child node rvalue
 * @return Reference to this node for method chaining
 * @note Creates a new copy of the moved node
 */
template <class T> Node<T> &Node<T>::setLeft(rvalue left) {
  this->left = new Node<T>(left);
  return *this;
}

/**
 * @brief Set right child (copy semantics)
 * @param right Right child node reference
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setRight(lvalue right) {
  this->right = &right;
  return *this;
}

/**
 * @brief Set right child (move semantics)
 * @param right Right child node rvalue
 * @return Reference to this node for method chaining
 * @note Creates a new copy of the moved node
 */
template <class T> Node<T> &Node<T>::setRight(rvalue right) {
  this->right = new Node<T>(right);
  return *this;
}

/**
 * @brief Set both children (copy semantics for both)
 * @param left Left child node reference
 * @param right Right child node reference
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setNodes(lvalue left, lvalue right) {
  this->left = &left;
  this->right = &right;
  return *this;
}

/**
 * @brief Set both children (move semantics for both)
 * @param left Left child node rvalue
 * @param right Right child node rvalue
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setNodes(rvalue left, rvalue right) {
  this->left = new Node<T>(left);
  this->right = new Node<T>(right);
  return *this;
}

/**
 * @brief Set both children (move left, copy right)
 * @param left Left child node rvalue
 * @param right Right child node reference
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setNodes(rvalue left, lvalue right) {
  this->left = new Node<T>(left);
  this->right = &right;
  return *this;
}

/**
 * @brief Set both children (copy left, move right)
 * @param left Left child node reference
 * @param right Right child node rvalue
 * @return Reference to this node for method chaining
 */
template <class T> Node<T> &Node<T>::setNodes(lvalue left, rvalue right) {
  this->left = &left;
  this->right = new Node<T>(right);
  return *this;
}

/* >-----> Getter Section <-----< */

/**
 * @brief Get node data (const version)
 * @return Const reference to the stored data
 */
template <class T> const T &Node<T>::getData(void) const { return this->data; }

/**
 * @brief Get left child node (non-const version)
 * @return Reference to left child node
 * @throws NodeExcept if left child is nullptr
 */
template <class T> Node<T> &Node<T>::getLeft(void) {
  if (this->left == nullptr) {
    throw NodeExcept(NONODE);
  }
  return *this->left;
}

/**
 * @brief Get left child node (const version)
 * @return Const reference to left child node
 * @throws NodeExcept if left child is nullptr
 */
template <class T> const Node<T> &Node<T>::getLeft(void) const {
  if (this->left == nullptr) {
    throw NodeExcept(NONODE);
  }
  return *this->left;
}

/**
 * @brief Get right child node (non-const version)
 * @return Reference to right child node
 * @throws NodeExcept if right child is nullptr
 */
template <class T> Node<T> &Node<T>::getRight(void) {
  if (this->right == nullptr) {
    throw NodeExcept(NONODE);
  }
  return *this->right;
}

/**
 * @brief Get right child node (const version)
 * @return Const reference to right child node
 * @throws NodeExcept if right child is nullptr
 */
template <class T> const Node<T> &Node<T>::getRight(void) const {
  if (this->right == nullptr) {
    throw NodeExcept(NONODE);
  }
  return *this->right;
}

/* >=====> Friend Section <=====< */

/**
 * @brief Equality comparison operator
 * @param first First node to compare
 * @param second Second node to compare
 * @return true if node data is equal
 */
template <class OT>
bool operator==(const Node<OT> &first, const Node<OT> &second) {
  return first.data == second.data;
}

/**
 * @brief Inequality comparison operator
 * @param first First node to compare
 * @param second Second node to compare
 * @return true if node data is not equal
 */
template <class OT>
bool operator!=(const Node<OT> &first, const Node<OT> &second) {
  return first.data != second.data;
}

/**
 * @brief Stream output operator
 * @param os Output stream
 * @param node Node to output
 * @return Reference to output stream for chaining
 * @note Outputs the node's data to the stream
 */
template <class OT> std::ostream &operator<<(std::ostream &os, Node<OT> node) {
  os << node.getData();
  return os;
}
