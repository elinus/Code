#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V, int E = 0) : V(V), E(E), adjList(new list<int>[V]) {}
  ~Graph() { delete[] adjList; }
  void addEdge(int u, int v);
  void color();

private:
  int V, E;
  list<int> *adjList;
};

void Graph::addEdge(int u, int v) {
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

template <typename T> void print(const string &tag, const vector<T> &vec) {
  cout << tag << " : ";
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}

void Graph::color() {
  vector<int> result(V, -1);
  vector<bool> available(V, false);
  result[0] = 0;
  for (int v = 1; v < V; v++) {
    list<int>::iterator it;
    for (it = adjList[v].begin(); it != adjList[v].end(); it++) {
      if (result[*it] != -1) {
        available[result[*it]] = true;
      }
    }
    int cr = 0;
    for (cr = 0; cr < V; cr++) {
      if (!available[cr])
        break;
    }
    result[v] = cr;

    for (it = adjList[v].begin(); it != adjList[v].end(); it++) {
      if (result[*it] != -1) {
        available[result[*it]] = false;
      }
    }
  }
  print("result", result);
}

int main() {
  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 2);
  g1.addEdge(1, 3);
  g1.addEdge(2, 3);
  g1.addEdge(3, 4);
  g1.color();
  return 0;
}