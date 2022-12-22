#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1e6;

int partition(int arr[], int left, int right) {
  int pivot = arr[right];
  int vt = left - 1;
  for (int i = left; i <= right - 1; i++) {
    if (arr[i] < pivot) {
      vt++;
      swap(arr[i], arr[vt]);
    }
  }
  vt = vt + 1;
  swap(arr[vt], arr[right]);
  return vt;
}

void quick_sort(int arr[], int left, int right) {
  using ii = pair<int, int>;
  stack<ii> st;
  st.push({left, right});
  while (!st.empty()) {
    ii top = st.top();
    st.pop();
    int l = top.first, r = top.second;
    if (l >= r)
      continue;
    int pi = partition(arr, l, r);
    st.push({l, pi - 1});
    st.push({pi + 1, r});
  }
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quick_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
  cout << endl;
  return 0;
}
