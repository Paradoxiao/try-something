#include <iostream>
#include <random>
using namespace std;
int my_merge(int *a, int sa, int *b, int sb, int *c) {
  int i = 0, j = 0, k = 0;
  while (i < sa && j < sb)
    if (a[i] > b[j])
      c[k++] = b[j++];
    else
      c[k++] = a[i++];
  while (j < sb)
    c[k++] = b[j++];
  while (i < sa)
    c[k++] = a[i++];
  return k;
}
void my_merge_sort(int *a, int l, int r, int *c) {
  if (l >= r - 1)
    return;
  int mid = (l + r) / 2;
  my_merge_sort(a, l, mid, c);
  my_merge_sort(a, mid, r, c);
  int sa = mid - l, sb = r - mid;
  my_merge(a + l, sa, a + mid, sb, c);
  for (int i = l; i < r; i++)
    a[i] = c[i - l];
}
void my_swap(int &a, int &b) {
  int temp = a;
  a = b, b = temp;
}
void my_quick_sort(int *a, int l, int r) {
  static mt19937 random;
  if (l >= r)
    return;
  int p = a[random() % (r - l + 1) + l];
  int i = l, j = r;
  while (1) {
    while (a[i] < p)
      ++i;
    while (a[j] > p)
      --j;
    if (i >= j)
      break;
    my_swap(a[i++], a[j--]);
  }
  my_quick_sort(a, l, i - 1);
  my_quick_sort(a, j + 1, r);
}
int main() {
  int n[100];
  mt19937 a;
  for (int &i : n)
    i = a() % 1000;
  int *c = new int[100];
  my_merge_sort(n, 0, 100, c);
  for (int i : n)
    cout << i << " ";
  return 0;
}
