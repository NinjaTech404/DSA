#include <iostream>
#include "merge_sort.hpp"
using namespace std;
int main (){
  int arr[] = {17, 22, -100, 14, 9, 0, 11, -2};
  // >=====> unsorted array <=====<
  cout << "Unsorted Array: ";
  for (size_t i = 0; i < size(arr); i++) { cout << arr[i] << ' '; }
  cout << endl;
  // >=====> sorted array <=====<
  Algorithms::merge_sort(arr, 0, size(arr) - 1);
  cout << "sorted Array  : ";
  for (size_t i = 0; i < size(arr); i++) { cout << arr[i] << ' '; }
  cout << endl;
  return 0;
}
