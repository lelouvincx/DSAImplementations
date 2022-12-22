#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 1e6;

void shaker_sort(int a[], int n) {
  for (int i = 0; i < n / 2; ++i) {
    bool is_swap = false;
    for (int j = i; j < n - 1 - i; ++j)
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        is_swap = true;
      }
    for (int j = n - 2 - i; j > i; --j)
      if (a[j - 1] > a[j]) {
        swap(a[j - 1], a[j]);
        is_swap = true;
      }
    if (is_swap == false)
      break;
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  shaker_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
