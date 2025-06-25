#include <chrono>
#include <iostream>
#include <random>
#include <string>
using namespace std;
int main() {
  mt19937 r(chrono::high_resolution_clock::now().time_since_epoch().count());
  for (int i = 0; i < 10; i++) {
    int j = r() % 100;
    cout << j << endl;
    for (int i = 0; i < j; i++)
      cout << r() % 2147483647 << " ";
    cout << endl;
  }
  return 0;
}
