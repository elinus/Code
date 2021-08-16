#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
  int capacity;
  int size;
  vector<int> heap;

public:
  PriorityQueue(int capacity)
      : capacity(capacity), size(0), heap(vector<int>(capacity)) {}
  ~PriorityQueue() = default;
  bool push(int value) {
    if (size + 1 > capacity) {
      cerr << "Queue is full" << endl;
      return false;
    }
    heap[size] = value;
    int curr = size;
    while (curr > 0 && heap[curr] < heap[(curr - 1) / 2]) {
      swap(heap[curr], heap[(curr - 1) / 2]);
      curr = (curr - 1) / 2;
    }
    size++;
    return true;
  }
  int pop(int &value) {
    if (size <= 0)
      return -1;
    value = heap[0];
    size--;
    heap[0] = heap[size];
    int curr = 0;
    while (curr * 2 + 1 < size) {
      int child;
      if (curr * 2 + 2 == size)
        child = curr * 2 + 1;
      else
        child = heap[curr * 2 + 1] < heap[curr * 2 + 2] ? curr * 2 + 1
                                                        : curr * 2 + 2;
      if (heap[curr] < heap[child])
        break;
      swap(heap[curr], heap[child]);
      curr = child;
    }
    return 1; //  true
  }
};

int main(int argc, const char **argv) { return 0; }