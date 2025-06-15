#include <iomanip>
#include <iostream>
using namespace std;
int i = 0;
void my_swap(int &a, int &b) {
  int temp = a;
  a = b, b = temp;
}
void my_permute(int *arr, int n, int k) {
  if (k == n) {
    cout << setw(3) << setfill(' ') << ++i << ": ";
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
    return;
  }
  for (int i = k; i < n; i++) {
    my_swap(arr[k], arr[i]);
    my_permute(arr, n, k + 1);
    my_swap(arr[k], arr[i]);
  }
}
int main() {
  int arr[] = {1, 2, 3, 4};
  my_permute(arr, 4, 0);
  return 0;
}
