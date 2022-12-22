#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1e6;

int binary_search(int a[], int val, int left, int right) {
  if (right <= left) {
    if (val > a[left])
      return left + 1;
    else
      return left;
  }
  int mid = left + (right - left) / 2;
  if (val == a[mid])
    return mid + 1;
  if (val < a[mid])
    return binary_search(a, val, left, mid - 1);
  return binary_search(a, val, mid + 1, right);
}

void binary_insertion_sort(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    int j = i - 1;
    int selected = a[i];
    int loc = binary_search(a, selected, 0, j);
    while (j >= loc) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = selected;
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  binary_insertion_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
