#include <linear.hpp>
#include <iostream>
using namespace std;
int main() {
  const char * arr[] = {"Saif", "Ali", "Mohammed", "Kadhim"};
  cout << "Found at: " << linear::rec_linear_search_algo(arr, 4,"Kadhim") << endl;
  return 0;
}
