/*
 * Heap Sort Implementation
 * 
 * A comprehensive implementation of heap sort algorithm including both
 * max-heap and min-heap variations. This library provides template-based
 * heap operations for generic data types.
 * 
 * Features:
 * - Max heap construction and sorting
 * - Min heap construction and sorting
 * - Generic template support for any data type
 * - Efficient O(n log n) sorting algorithm
 * - In-place sorting (no extra memory allocation)
 * 
 * Author: KADHIM SHAKIR
 * Email: kadhimshakir@yahoo.com
 * GitHub: https://github.com/NinjaTech404
 * Created: 2026
 * License: MIT
 */

template<class T>
/* >=====> Dedicated Swap Function For Heap <=====< */
void swap(T& a, T& b){
  T temp = a;
  a = b;
  b = temp;
}

/* >=====> Max Heapify <=====< */
template<class T>
void heapify(T arr[], size_t size, size_t root){ //=> effects only one single subtree
  size_t largest, left, right;
  largest = root; //=> largest is the root node index
  left    = 2 * root + 1; //=> left node index 
  right   = 2 * root + 2; //=> right node index
  
  if(left < size && (arr[left] > arr[largest])){ //=> sets left the largest
    largest = left; 
  }

  if(right < size && (arr[right] > arr[largest])){ //=> sets right the largest
    largest = right; 
  }

  if(largest != root){ 
    swap(arr[root], arr[largest]); //=> swapping root with largest value of a subtree

    heapify(arr, size, largest); //=> recursively heapifying the subtree 
  } 
}

/* >=====> Max Heap Sort <=====< */
template<class T>
void heap_sort(T arr[], size_t size){
  
  //=> Heapifying all subtrees
  for(size_t i = size / 2 - 1; (i >= 0) && (i < size); --i){ //=> subtree root index = ((child index) / 2) - 1
                                           //=> i >= 0 is always true fot size_t type, so i is wraped with (i < size)
    heapify(arr, size, i); //=> heapify subtrees one by one
                           //=> from the lowest subtree level (bottom-up)
  }

  //=> Sorting the array
  for(size_t i = size - 1; (i >= 0) && (i < size); --i){ //=> i is the last node index
    swap(arr[0], arr[i]); //=> swap the root with last node
    heapify(arr, i, 0); //=> heapifying all subtrees
  }
}

/* >=====> Min Heapify <=====< */
template<class T>
void min_heapify(T arr[], size_t size, size_t root){
  size_t smallest, left, right;
  smallest = root; //=> initialize smallest as root
  left     = 2 * root + 1; //=> left child index
  right    = 2 * root + 2; //=> right child index
  
  if(left < size && (arr[left] < arr[smallest])){ //=> if left child is smaller than root
    smallest = left; //=> update smallest to left
  }

  if(right < size && (arr[right] < arr[smallest])){ //=> if right child is smaller than current smallest
    smallest = right; //=> update smallest to right
  }

  if(smallest != root){ //=> if smallest is not root
    swap(arr[root], arr[smallest]); //=> swap root with smallest
    min_heapify(arr, size, smallest); //=> recursively heapify the affected subtree
  }
}

/* >=====> Min Heap Sort <=====< */
template<class T>
void min_heap_sort(T arr[], size_t size){
  //=> Build min heap (rearrange array)
  for(size_t i = (size / 2) - 1; (i >= 0) && (i < size); --i){
    min_heapify(arr, size, i); //=> build min heap from bottom up
  }
 
  //=> Extract elements from heap one by one
  for(size_t i = size - 1; (i >= 0) && (i < size); --i){
    swap(arr[0], arr[i]); //=> move current root to end
    min_heapify(arr, i, 0); //=> call min heapify on reduced heap
  }
}
