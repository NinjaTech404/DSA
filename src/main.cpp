#include <binary.hpp>
#include <iostream>
using namespace std;
int main() {
  const char * arr[] = {"Ali", "Ahmed", "Yassir", "Kadhim"};
  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << binary::rec_binary_search(arr, "Yassir") << endl;
  return 0;
}
