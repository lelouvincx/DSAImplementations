#include <iostream>
using namespace std;
#define MAX 100001

void bubble_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j >= i + 1; j--) {
      if (a[j] < a[j - 1])
        swap(a[j], a[j - 1]);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bubble_sort(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
  return 0;
}
