#ifndef QUAD_HPP
#define QUAD_HPP

#include <cstddef> //=> for size_t
#include <algorithm> //=> for swap function

namespace quad{
  /* >=====> Quadratic Algorithms <=====<*/

  /* >-----> 1. Sorting Algorithms <-----< */

  //=> 1-1. Bubble Sort Algorithm
  template<class T, size_t N> //=> Worst = Average = O(n^2), Best = O(n), Space Complexity = O(1).
  void bubble_sort(T (&arr)[N]); //=> (&arr)[N] is an array reference, not an array pointer.

  //=> 1-2. Selection Sort Algorithm
  template<class T, size_t N> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1);
  void selection_sort(T (&arr)[N]); //=> (&arr)[N] is an array reference, not an array pointer.

  #include "quad.cpp" //=> the implementaion file
}

#endif
