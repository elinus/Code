#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
  Graph(int V, int E = 0) : V(V), E(E), adjList(new list<int>[V]) {}
  ~Graph() { delete[] adjList; }
  void addEdge(int u, int v) { adjList[u].push_back(v); }

private:
  int V, E;
  list<int> *adjList;
};

int main() { return 0; }