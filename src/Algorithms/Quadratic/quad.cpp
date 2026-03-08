/* >=====> Quadratic Algorithms <=====<*/

/* >-----> 1. Sorting Algorithms <-----< */

//=> 1-1. Bubble Sort Algorithm
template<class T, size_t N> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1).
void bubble_sort(T (&arr)[N]){ //=> (&arr)[N] is an array reference, not an array pointer.
  for(size_t i = 0; i < N; i++){
    for(size_t j = 0; j < N - 1; j++){
      if(arr[j] > arr[j + 1]){
        T temp   = arr[j];
        arr[j]   = arr[j + 1];
        arr[j+1] = temp;
      }
    }
  }
}
template<class T> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1).
void bubble_sort(T* arr, size_t N){ //=> This Overloaded Version is for manual size evaluation.
  for(size_t i = 0; i < N; i++){
    for(size_t j = 0; j < N - 1; j++){
      if(arr[j] > arr[j + 1]){
        T temp   = arr[j];
        arr[j]   = arr[j + 1];
        arr[j+1] = temp;
      }
    }
  }
}

//=> 1-2. Selection Sort Algorithm
template<class T, size_t N> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1);
void selection_sort(T (&arr)[N]){ //=> (&arr)[N] is an array reference, not an array pointer.
  size_t pivot;
  for(size_t i = 0; i < N; i++){
    pivot = i;
    for(size_t j = i + 1; j < N; j++){
      if(arr[pivot] > arr[j]){
        pivot = j;
      }
    }
    std::swap(arr[pivot], arr[i]);
  }
}
template<class T> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1);
void selection_sort(T* arr, size_t N){ //=> This Overloaded Version is for manual size evaluation.
  size_t pivot;
  for(size_t i = 0; i < N; i++){
    pivot = i;
    for(size_t j = i + 1; j < N; j++){
      if(arr[pivot] > arr[j]){
        pivot = j;
      }
    }
    std::swap(arr[pivot], arr[i]);
  }
}

//=> 1-3. Insertion Sort Algorithm
template<class T, size_t N> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1).
void insertion_sort(T (&arr)[N]){ //=> (&arr)[N] is an array reference, not an array pointer.
  for(size_t i = 1; i < N; i++){
    size_t j = i;
    while(j > 0 && arr[j - 1] > arr[j]){
      std::swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}
template<class T> //=> Worst = Average = Best = O(n^2), Space Complexity = O(1).
void insertion_sort(T* arr, size_t N){ //=> This Overloaded Version is for manual size evaluation.
  for(size_t i = 1; i < N; i++){
    size_t j = i;
    while(j > 0 && arr[j - 1] > arr[j]){
      std::swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}
