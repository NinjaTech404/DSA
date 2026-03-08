/* >=====> 1. Binary Search Algorithm based on Divide & Conquer Algorithms <=====< */

/* >-----> 1-1. Non-Rcursive Binary Search <-----< */
template<class T, size_t N> //=> Worst = Average = O(log n), Best = O(1), Space Complexity = O(1)
size_t binary_search(T (&arr)[N], T key){ //=> (&arr)[N] is an array reference, not a pointer.
  size_t low = 0, high = N - 1;

  while(low <= high){
    size_t mid = (low + high)/2;

    if(arr[mid] == key){ return mid; }

    else if(arr[mid] < key){ low = mid + 1; }

    else { high = mid - 1; }
  }

  return -1;
}

template<class T> //=> Worst = Average = O(log n), Best = O(1), Space Complexity = O(1)
size_t binary_search(T* arr, T key, size_t N){ //=> This Overloaded Version is for manual size evaluation.
  size_t low = 0, high = N - 1;

  while(low <= high){
    size_t mid = (low + high)/2;

    if(arr[mid] == key){ return mid; }

    else if(arr[mid] < key){ low = mid + 1; }

    else { high = mid - 1; }
  }

  return -1;
}


/* >-----> 1-2. Recursive Binary Search <-----< */
template<class T> //=> Recursive Binary Search Algorithm Function
size_t rec_binary_search_algo(T* arr, T key, size_t low, size_t high){
  if(low <= high ){
    size_t mid = (low + high)/2;

    if(arr[mid] == key){ return mid; }

    else if(arr[mid] < key){ 
      return rec_binary_search_algo(arr, key, mid + 1, high);
    }

    else {
      return rec_binary_search_algo(arr, key, low, mid - 1);
    }
  }
  return -1;
}

template<class T, size_t N> //=> A Wrapper Function For Better Experience.
size_t rec_binary_search(T (&arr)[N], T key){ //=> Worst = Average = O(log n), Best = O(1), Space Complexity = O(1)
  return rec_binary_search_algo(arr, key, 0, N - 1);
}

template<class T> //=> A Wrapper Function For Better Experience.
size_t rec_binary_search(T* arr, T key, size_t N){ //=> This Overloaded Version is for manual size evaluation.
  return rec_binary_search_algo(arr, key, 0, N - 1);
}
