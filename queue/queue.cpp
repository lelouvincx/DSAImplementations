// You can implement queue by yourself or use the standard library's
#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

const int maxn = 1e6;

struct Queue {
  Queue(const Queue &) = default;
  Queue(Queue &&) = default;
  Queue &operator=(const Queue &) = default;
  Queue &operator=(Queue &&) = default;
  int head, tail;
  int val[maxn];

  Queue(int _idx = 0) {
    head = -1;
    tail = 0;
  }

public:
  void push(int x) {
    ++head;
    val[head] = x;
  }

  void pop() {
    assert(head-tail+1 > 0); // make sure stack contains at least 1 element
    ++tail;
  }

  int front() {
    return val[tail];
  }

  int size() {
    return head-tail+1;
  }

  bool empty() {
    return size() == 0;
  }
};

int main() {
  Queue que;
  que.push(1); que.push(2); que.push(3);
  if (que.empty())
    cout << "Queue is empty!" << endl;
  else
    cout << "Queue has elements!" << endl;
  while (!que.empty()) {
    cout << que.front() << endl; 
    que.pop();
  }
  return 0;
}
