#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1e6;

// Calculate base integer logarithm of x
int int_log(int base, int x) { return int(log(x) / log(base)); }

// Calculate a powers x
int int_pow(int a, int x) {
  if (x == 0)
    return 1;
  int tmp = int_pow(a, x / 2);
  if (x % 2 == 1)
    return x * tmp;
  return tmp * tmp;
}

void radix_sort(int a[], int n, int base = 10) {
  // Finx max element of a[]
  int mx = a[0];
  for (int i = 1; i < n; ++i)
    if (mx < a[i])
      mx = a[i];

  int max_digit = int_log(base, mx) + 2;

  int *copy_a = new int[n];
  int *cnt_digit = new int[base];

  // For each digit from 0 to max_digit, execute counting sort inside the array
  for (int digit = 0; digit <= max_digit; ++digit) {
    // Initial the counting array
    for (int i = 0; i < base; ++i)
      cnt_digit[i] = 0;

    // For each element in a[] take the digit at the 'digit' position
    for (int i = 0; i < n; ++i) {
      int digit_of_ai = (a[i] / int_pow(base, digit)) % base;
      cnt_digit[digit_of_ai]++;
    }

    // Turn cnt_digit into prefix sum
    for (int i = 1; i < base; ++i)
      cnt_digit[i] += cnt_digit[i - 1];

    // Counting sort
    for (int i = n - 1; i >= 0; --i) {
      int digit_of_ai = (a[i] / int_pow(base, digit)) % base;
      cnt_digit[digit_of_ai]--;
      copy_a[cnt_digit[digit_of_ai]] = a[i];
    }

    // Copy a back from copy_a
    for (int i = 0; i < n; ++i)
      a[i] = copy_a[i];
  }

  delete[] copy_a;
  delete[] cnt_digit;
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  radix_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
