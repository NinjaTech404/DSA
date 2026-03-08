/*
 * Heap Sort Library Header
 * 
 * Template-based heap sort implementation with both max-heap and min-heap
 * sorting capabilities. This header provides the interface declarations
 * for heap operations.
 * 
 * Usage:
 *   #include "heap.hpp"
 *   int arr[] = {5, 2, 8, 1, 9};
 *   size_t size = std::size(arr);
 *   heap::heap_sort(arr, size);    // ascending order
 *   heap::min_heap_sort(arr, size); // descending order
 * 
 * Author: KADHIM SHAKIR
 * Email: kadhimshakir@yahoo.com
 * GitHub: https://github.com/NinjaTech404
 * Created: 2026
 * License: MIT
 */

#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef> //=> for size_t
#include <algorithm> //=> for swap function

namespace heap { //=> wraping evreything in "heap" namespace for safety

//=> Forward declarations
template<class T> void heapify(T arr[], size_t N, size_t root); //=> heapify a single subtree
template<class T> void heap_sort(T arr[], size_t N); //=> the actual sorting function with a ascending order
template<class T, size_t N> void heap_sort(T (&arr)[N]); //=> This Overloaded Version is for a predfined array


template<class T> void min_heapify(T arr[], size_t N, size_t root); //=> heapify a single subtree
template<class T> void min_heap_sort(T arr[], size_t N); //=> the actual sorting function with a descending order
template<class T, size_t N> void min_heap_sort(T (&arr)[N]); //=> This Overloaded Version is for a predfined array

#include "heap.cpp" //=> the implementaion file

}

#endif
