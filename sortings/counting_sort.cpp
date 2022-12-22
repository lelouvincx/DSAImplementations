#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int MAX = 1e6;

void counting_sort(int a[], int n) {
  // Prepare a hash table here, it will store and count the number of distinct
  // elements
  map<int, int> cnt; // Or we can use unordered_map

  for (int i = 0; i < n; ++i)
    cnt[a[i]]++;

  // Rebuild the array
  int i = 0;
  for (auto x : cnt) {
    for (; x.second > 0; x.second--)
      a[i++] = x.first;
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  counting_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << '\n';
  return 0;
}
