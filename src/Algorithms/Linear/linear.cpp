/* >====> Non-Rcursive Linear Search Function <====<*/
template<class T>
size_t non_rec_linear_search(T* arr, T key, size_t  N){
  bool is_found = false;
  size_t i;
  for(i = 0; i < N; i++){
    if(arr[i] == key){
      is_found = true;
      break;
    }
    continue;
  } 
  return is_found? i : LIMIT;
}

/* >====> Rcursive Linear Search Function <====<*/
template<class T>
size_t rec_linear_search (T* arr, T key, size_t N){
  if(--N >= 0 && N != LIMIT){
    if (arr[N] == key){
      return N;
    }
  }
  else { 
    throw std::out_of_range("Key not found or index went out of range!");
  }
  return rec_linear_search(arr, key, N);
}

