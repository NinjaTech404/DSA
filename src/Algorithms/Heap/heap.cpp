template<class T>
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
void heapSort(T arr[], size_t size){
  
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
