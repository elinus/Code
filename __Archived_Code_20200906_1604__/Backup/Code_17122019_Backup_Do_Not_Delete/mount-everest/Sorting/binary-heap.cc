#include <iostream>
#include <climits>
#include <algorithm>

class MinHeap {
    private:
        int m_capacity;
        int m_heapSize;
        int *m_heapArray;
    public:
        MinHeap(int capacity) {
            m_capacity = capacity;
            m_heapSize = 0;
            m_heapArray = new int[capacity];
        }
        ~MinHeap() {
            delete [] m_heapArray;
        }
        int parent(int i) { return (i-1) / 2; }
        int left(int i) { return 2*i + 1; }
        int right(int i) { return 2*i + 2; }
        int getMin() { return m_heapArray[0]; }
        void minHeapify(int i);
        void insertKey(int i);
        int extractMin();
        void decreaseKey(int i, int new_value);
        void deleteKey(int i);
};

void MinHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < m_heapSize && m_heapArray[l] < m_heapArray[i]) {
        smallest = l;
    }
    if (r < m_heapSize && m_heapArray[r] < m_heapArray[smallest]) {
        smallest = r;
    }
    if (i != smallest) {
        std::swap(m_heapArray[i], m_heapArray[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::insertKey(int key) {
    if (m_heapSize == m_capacity) {
        std::cout <<"Error: Overflow!\n";
        return;
    }
    int i = m_heapSize;
    m_heapArray[i] = key;
    m_heapSize++;
    while (i != 0 && m_heapArray[parent(i)] > m_heapArray[i]) {
        std::swap(m_heapArray[parent(i)], m_heapArray[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (m_heapSize <= 0) {
        return INT_MAX;
    } 
    if (m_heapSize == 1) {
        m_heapSize--;
        return m_heapArray[0];
    }
    int root = m_heapArray[0];
    m_heapArray[0] = m_heapArray[m_heapSize - 1];
    m_heapSize--;
    minHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int new_value) {
    m_heapArray[i] = new_value;
    while (i != 0 && m_heapArray[parent(i)] > m_heapArray[i]) {
        std::swap(m_heapArray[parent(i)], m_heapArray[i]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main (int argc, char *argv[]) {
    MinHeap heap(10);
    heap.insertKey(3);
    heap.insertKey(2);
    heap.deleteKey(1);
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);
    std::cout << heap.extractMin() << " ";
    std::cout << heap.getMin() << " ";
    heap.decreaseKey(2, 1);
    std::cout << heap.getMin() << "\n";
    return 0;
}

