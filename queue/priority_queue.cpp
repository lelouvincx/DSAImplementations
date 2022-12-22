// In this implementation I use binary heap with array to
// present priority queue
#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

const int maxn = 1e6;

struct PriorityQueue {
  int size = -1;
  int arr[maxn];

  PriorityQueue(int _size = -1) {
    size = -1;
  }

private:
  int parent(int i) {
    return (i-1)/2;
  }

  int leftChild(int i) {
    return ((2*i)+1);
  }

  int rightChild(int i) {
    return ((2*i)+2);
  }

  void upHeap(int i) {
    while (i > 0 && arr[parent(i)] < arr[i]) {
      swap(arr[parent(i)], arr[i]);
      i = parent(i);
    }
  }

  void downHeap(int i) {
    int maxIndex = i;

    int l = leftChild(i);
    if (l <= size && arr[l] > arr[maxIndex])
      maxIndex = l;

    int r = rightChild(i);
    if (r <= size && arr[r] > arr[maxIndex])
      maxIndex = r;

    if (i != maxIndex) {
      swap(arr[i], arr[maxIndex]);
      downHeap(maxIndex);
    }
  }

public:
  void push(int x) {
    ++size;
    arr[size] = x;
    upHeap(size);
  }

  int top() {
    return arr[0];
  }

  void pop() {
    arr[0] = arr[size];
    --size;
    downHeap(0);
  }

  bool empty() {
    return size == 0;
  }
};

int main() {
  /*
             45
          /      \
         31      14
        /  \    /  \
       13  20  7   11
      /  \
     12   7
  */
  PriorityQueue pq;
  int input[] = {45, 20, 14, 12, 31, 7, 11, 13, 7};
  for (int i = 0; i <= 9; ++i) 
      pq.push(input[i]);

  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  return 0;
}
