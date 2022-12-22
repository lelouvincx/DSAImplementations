// You can use both insertion sort or merge sort for step 3
// In this code, I use merge sort
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1e6;
const int MAX2 = 450010;
int last_index[MAX2], number_of_elements_in_class[MAX2];

void insertion_sort(int a[], int n) {
  int k = 1;
  while (k < n) {
    int x = a[k];
    int pos = k - 1;
    while (a[pos] > x && pos >= 0) {
      a[pos + 1] = a[pos];
      pos--;
    }
    a[pos + 1] = x;
    k++;
  }
}

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

int calculate_class(int x, int m, int min_val, int max_val) {
  return (m - 1) * (x - min_val) / (max_val - min_val);
}

void flash_sort(int a[], int n) {
  // Step 1: Classification
  int min_val, max_val;
  min_val = max_val = a[0];
  for (int i = 1; i < n; ++i) {
    if (min_val > a[i])
      min_val = a[i];
    if (max_val < a[i])
      max_val = a[i];
  }

  int m = 0.43 * n;
  last_index[0] = -1;
  for (int i = 0; i < n; ++i) {
    int tmp = calculate_class(a[i], m, min_val, max_val);
    last_index[tmp]++;
    number_of_elements_in_class[tmp]++;
  }
  for (int i = 1; i < m; ++i)
    last_index[i] += last_index[i - 1];

  int number_of_moves = n - 1;
  for (int moves = 0; moves < number_of_moves; ++moves) {
    int tmp = calculate_class(a[0], m, min_val, max_val);
    if (last_index[tmp] >= 0)
      swap(a[0], a[last_index[tmp]]);
    else
      break;
    last_index[tmp]--;
  }

  int left = 0, right = -1, i = 0;
  do {
    left = right + 1;
    right = left + number_of_elements_in_class[i++] - 1;
    merge_sort(a, left, right);
  } while (i < m);
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  flash_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
