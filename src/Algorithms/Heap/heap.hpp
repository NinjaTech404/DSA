#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef> //=> for size_t
namespace heap { //=> wraping evreything in "heap" namespace for safety
  
//=> Forward declarations
template<class T> void swap(T& a, T& b); //=> swap function
template<class T> void heapify(T arr[], size_t size, size_t root); //=> heapify a single subtree
template<class T> void heapSort(T arr[], size_t size); //=> the actual sorting function

#include "heap.cpp" //=> the implementaion file

}
#endif
