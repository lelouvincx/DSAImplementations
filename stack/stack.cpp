// You can implement stack by yourself or use the standard library's
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

const int maxn = 1e6;

struct Stack {
  Stack(const Stack &) = default;
  Stack(Stack &&) = default;
  Stack &operator=(const Stack &) = default;
  Stack &operator=(Stack &&) = default;
  int idx;
  int val[maxn];

  Stack(int _idx = 0) {
    idx = _idx;
  }

public:
  void push(int x) {
    ++idx;
    val[idx] = x;
  }

  void pop() {
    assert(idx); // make sure stack contains at least 1 element
    --idx;
  }

  int top() {
    return val[idx];
  }

  int size() {
    return idx;
  }

  bool empty() {
    return size() == 0;
  }
};

int main() {
  Stack st;
  st.push(1); st.push(2); st.push(3);
  if (st.empty())
    cout << "Stack is empty!" << endl;
  else
    cout << "Stack has elements!" << endl;
  while (!st.empty()) {
    cout << st.top() << endl; 
    st.pop();
  }
  return 0;
}
