#pragma once
namespace Algorithms{
  typedef long unsigned int size_t;
  template<class T>
  void merge_array (T arr[], size_t l, size_t mid_index, size_t h){ // ==> T(n) = n & S(n) = nlogn
    size_t temp_array_size = h - l + 1;
    T temp_array[temp_array_size]; // ==> a temporary array
    size_t i = l, j = mid_index + 1, k = 0; // ==> setting indeces
    /* >=====> insert and sort elements of arr into temp_array <=====< */
    while (i <= mid_index && j <=h){
      if(arr[i] <= arr[j]){
        temp_array[k] = arr[i];
        i++;
      }
      else {
        temp_array[k] = arr[j];
        j++;
      }
      k++;
    }
    /* >=====> copy the leftover elemets of arr into temp_array <=====< */
    while(i <= mid_index){
      temp_array[k] = arr[i];
      i++; k++;
    }
    while(j <= h){
      temp_array[k] = arr[j];
      j++; k++;
    }
    /* >=====> copy back the elements of temp_array into arr <=====< */
    for (size_t it = 0; it < temp_array_size; it++) {
      arr[l + it] = temp_array[it]; // ==> [l + it] is the first element of arr
    }
  }

  template<class T>
  T* merge_sort(T arr[], size_t l, size_t h){ // ==> T(n) = 2T(n/2) + Cn
    if(l < h){ // ==> check if l & h are't acrossing each other
      size_t mid_index = (l + h)/2; // ==> mid index
      merge_sort(arr, l, mid_index); // ==> T(n/2) = T(n/2)
      merge_sort(arr, mid_index + 1, h); // ==> T(n) = T(n/2)
      merge_array<T>(arr, l, mid_index, h); // ==> T(n) = n & S(n) = nlogn
    }
    return arr;
  }
}
