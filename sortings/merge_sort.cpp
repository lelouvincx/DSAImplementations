#include <iostream>
using namespace std;
#define MAX 100001

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int LEFT[n1], RIGHT[n2];
  for (int i = 0; i < n1; i++)
    LEFT[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    RIGHT[j] = arr[mid + 1 + j];
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (LEFT[i] <= RIGHT[j]) {
      arr[k] = LEFT[i];
      i++;
    } else {
      arr[k] = RIGHT[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = LEFT[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = RIGHT[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  merge_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
  return 0;
}
