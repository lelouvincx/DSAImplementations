#include <iostream>
using namespace std;
#define MAX 100001

void selection_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int tempt = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[tempt])
        tempt = j;
    }
    swap(a[i], a[tempt]);
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selection_sort(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
  return 0;
}
