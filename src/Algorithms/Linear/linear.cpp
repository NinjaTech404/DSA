/* >=====> 1. Linear Search Algorithms <=====<*/

/* >-----> 1-1. Non-Reccursive Linear Search ALgorithms <-----<*/

//=> 1-1-1. Normal Linear Search || best = average = worst = O(n), Space Complexity = O(1)
template <class T, size_t N>
size_t linear_search(T (&arr)[N], T key){ //=> (&arr)[N] is an array reference not a pointer
  for(size_t i = 0; i < N; i++){
    if(arr[i] == key){ return i; }
  }
  return LIMIT;
}


/* >-----> 1-2. Reccursive Linear Search ALgorithms <-----<*/

//=> 1-2-1. Normal Linear Search || best = average = worst = O(n), Space Complexity = O(1)
template <class T> //=> Reccursive Linear Search Algorithm
size_t rec_linear_search_algo(T* arr, size_t N, T key){
  if(--N != LIMIT && N >= 0){
    if (arr[N] == key) { return N; }
    else { return rec_linear_search_algo(arr, N, key); }
  }
  return LIMIT;
}

template <class T, size_t N> //=> A Wrapper Function for Better Experience
size_t rec_linear_search (T (&arr)[N], T key){
  return rec_linear_search_algo(arr, N, key);
}
