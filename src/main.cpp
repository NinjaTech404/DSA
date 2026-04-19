#include <algorithm>
#include <cstddef>

//=> Bubble sort
void bubble(int *arr, size_t N) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < (N - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

//=> Slection Sort
void selection(int *arr, size_t N) {
  for (size_t i = 0; i < N; i++) {
    int min = i;
    for (size_t j = i + 1; j < N; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    std::swap(arr[i], arr[min]);
  }
}

//=> Insertion sort
void insertion(int *arr, size_t N) {
  for (size_t i = 1; i < N; i++) {
    size_t j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      std::swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}

//=> Binary Search
size_t binary_search(int *arr, int key, size_t low, size_t high) {
  size_t mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

size_t rec_binary_search(int *arr, int key, size_t low, size_t high) {
  size_t mid = (low + high) / 2;
  if (low <= high) {
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      return rec_binary_search(arr, key, mid + 1, high);
    } else {
      return rec_binary_search(arr, key, low, mid - 1);
    }
  }
  return -1;
}

//=> Heap Sort
void heapify(int *arr, size_t N, size_t root) {
  size_t largest = root;
  size_t left = (root * 2) + 1;
  size_t right = (root * 2) + 2;

  if ((left < N) && (arr[left] > arr[largest])) {
    largest = left;
  }

  if ((right < N) && (arr[right] > arr[largest])) {
    largest = right;
  }

  if (largest != root) {
    std::swap(arr[largest], arr[root]);
    heapify(arr, N, largest);
  }
}

void heap_sort(int *arr, size_t N) {
  for (size_t i = (N / 2) - 1; (i >= 0) && (i < N); i--) {
    heapify(arr, N, i);
  }

  for (size_t i = N - 1; (i >= 0) && (i < N); i--) {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0); //
  }
}

// => Merge Sort

void merge(int *arr, size_t low, size_t mid, size_t high) {
  size_t size = high - low + 1, temp[size];
  size_t i = low, j = mid + 1, k = 0;

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  while (j <= high) {
    temp[k++] = arr[j++];
  }

  for (size_t i = low; i < size; i++) {
    arr[i] = temp[i - low];
  }
}

void merge_sort(int *arr, size_t low, size_t high) {
  if (low < high) {
    size_t mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

#include <fmt/core.h>
#include <iostream>
using namespace fmt;
using namespace std;
int main(int argc, char **args) {

  //=> Setting the size
  size_t N = 0;
  print("Enter N: ");
  cin >> N;

  //=> Setting the elements
  int *arr = new int[N];
  print("Array: ");
  for (size_t i = 0; i < N; i++) {
    cin >> *(arr + i);
  }

  //=> Processing
  // 1. bubble(arr, N);
  // 2. selection(arr, N);
  // 3. insertion(arr, N);
  merge_sort(arr, 0, N - 1);
  //=> Outputing
  print("Result: ");
  for (size_t i = 0; i < N; i++) {
    print("{} ", *(arr + i));
  }
  cout << endl;

  // println("Key: {}", rec_binary_search(arr, 3, 0, N - 1));
  return 0;
}
