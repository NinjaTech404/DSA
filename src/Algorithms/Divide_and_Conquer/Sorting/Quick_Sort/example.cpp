#include<iostream>
#include"quick_sort.hpp" // in main.cpp use <Algorithms/Divide_and_Conquer/Sorting/Quick_Sort/quick_sort.hpp>
using namespace std;
int main (){
  int arr[] = {12, -1 , 0, 1, 10, -20 }; // ==> The Unsroted Array 

  // >==> before sorting <==<
  cout << "The Unsorted Array: ";
  for (size_t i = 0; i < size(arr); ++i) {
    cout << arr[i] << ' ';
  } cout << endl;

  // >==> after sorting <==<
  size_t low = 0, high = size(arr) - 1; // ==> setting the indeces
  Algorithms::quick_sort_first(arr, low, high); // ==> Or you can use quick_sort_last(arr, low, high);
  cout << "The Sorted Array  : ";
  for (size_t i = 0; i < size(arr); ++i) {
    cout << arr[i] << ' '; // ==> Output: -20 -1 0 1 10 12
  } cout << endl;

  return 0;
}
