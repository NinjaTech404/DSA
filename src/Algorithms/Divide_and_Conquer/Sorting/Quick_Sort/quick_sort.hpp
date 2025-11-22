#pragma once
namespace Algorithms{
  typedef long unsigned int size_t;
  template<class T>
  void swap (T& A, T& B) {
    T temp = A;
    A = B;
    B = temp;
  }
  template<class T>
  size_t partition_first(T arr[], size_t l, size_t h){
    size_t i = l, j = h + 1;
    T pivot = arr[l];
    while(i < j){
      do { i++; } while(i <= h && pivot >= arr[i]);
      do { j--; } while(j > l && pivot < arr[j]);
      if(i < j){
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[l], arr[j]); 
    return j;
  }
  template<class T>
  T* quick_sort_first(T arr[], size_t l, size_t h){
    if(l < h){
      size_t j = partition_first<T>(arr, l, h);
      if(j > l) { quick_sort_first<T>(arr, l, j - 1); }
      if(j < h) { quick_sort_first<T>(arr, j + 1, h); }
    }
    return arr;
  }
  template<class T>
  size_t partition_last(T arr[], size_t l, size_t h){
    size_t i = l - 1;
    T pivot = arr[h];
    for(size_t j = l; j < h; ++j){
      if(arr[j] <= pivot){ swap(arr[j], arr[++i]); }
    }
    swap(arr[h], arr[i+1]);
    return i + 1;
  }
  template<class T>
  T* quick_sort_last(T arr[], size_t l, size_t h){
    if(l < h){
      size_t i = partition_last<T>(arr, l, h);
      if(i > l) { quick_sort_last<T>(arr, l, i - 1); }
      if(i < h) { quick_sort_last<T>(arr, i + 1, h); }
    }
    return arr;
  }
}
