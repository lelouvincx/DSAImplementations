#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 1e6;

void shell_sort(int a[], int n) {
  int interval = 0;
  // Knuth's Formula
  while (interval < n / 3)
    interval = interval * 3 + 1;

  // Perform shell sort
  while (interval > 0) {
    for (int outer = interval; outer < n; ++outer) {
      int value_to_insert = a[outer];
      int inner = outer;
      while (inner - interval >= 0 && a[inner - interval] >= value_to_insert) {
        a[inner] = a[inner - interval];
        inner = inner - interval;
      }
      a[inner] = value_to_insert;
    }
    interval = (interval - 1) / 3;
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  shell_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
