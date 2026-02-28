#ifndef BINARY_HPP
#define BINARY_HPP

#include <cstddef>

namespace binary{
  /* >=====> 1. Binary Search Algorithm based on Divide & Conquer Algorithms <=====< */

  /* >-----> 1-1. Non-Rcursive Binary Search <-----< */
  template<class T, size_t N> //=> Worst = Average = O(log n), Best = O(1), Space Complexity = O(1)
  size_t binary_search(T (&arr)[N], T key); //=> (&arr)[N] is an array reference, not a pointer.

  /* >-----> 1-2. Recursive Binary Search <-----< */
  template<class T> //=> Recursive Binary Search Algorithm Function
  size_t rec_binary_search_algo(T* arr, T key, size_t low, size_t high);

  template<class T, size_t N> //=> A Wrapper Function For Better Experience.
  size_t rec_binary_search(T (&arr)[N], T key); //=> Worst = Average = O(log n), Best = O(1), Space Complexity = O(1)

  #include "binary.cpp" //=> the implementaion file
}

#endif
