#ifndef LINEAR_HPP
#define LINEAR_HPP

#include <cstddef>

namespace linear{
  //=> Some Constants
  constexpr size_t LIMIT = -1;

  /* >=====> 1. Linear Search Algorithms <=====<*/

  /* >-----> 1-1. Non-Reccursive Linear Search ALgorithms <-----<*/

  //=> 1-1-1. Normal Linear Search || best = average = worst = O(n), Space Complexity = O(n)
  template <class T, size_t N>
  size_t linear_search(T (&arr)[N], T key);

  /* >-----> 1-2. Reccursive Linear Search ALgorithms <-----<*/

  //=> 1-2-1. Normal Linear Search || best = average = worst = O(n), Space Complexity = O(n)
  template <class T> //=> Reccursive Linear Search Algorithm
  size_t rec_linear_search_algo(T* arr, size_t N, T key);

  template <class T, size_t N> //=> A Wrapper Function for Better Experience
  size_t rec_linear_search (T (&arr)[N], T key);

  #include "linear.cpp" //=> Implementation File
}

#endif

