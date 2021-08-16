#include <bits/stdc++.h>
using namespace std;

// Adjacency List
class Graph {
public:
  Graph(int V) : V{V}, adj{new list<int>[V]} {}
  ~Graph() { delete[] adj; }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  void print() {
    for (auto v = 0; v < V; v++) {
      cout << v << " |= ";
      if (adj[v].empty())
        cout << "E";
      else {
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
          cout << *it << " ";
        }
      }
      cout << "\n";
    }
    cout << "\n";
  }

  friend Graph transpose(const Graph &g);

private:
  int V;
  list<int> *adj;
};

Graph transpose(const Graph &g) {
  Graph tg(g.V);
  for (int v = 0; v < g.V; v++) {
    for (auto it = g.adj[v].begin(); it != g.adj[v].end(); ++it) {
      tg.add_edge(*it, v);
    }
  }
  return tg;
}

int main(int argc, char const *argv[]) {
  Graph g1(4);
  g1.add_edge(0, 1);
  g1.add_edge(0, 2);
  g1.add_edge(2, 0);
  g1.add_edge(2, 3);
  g1.add_edge(3, 3);
  g1.print();

  transpose(g1).print();
  transpose(transpose(g1)).print();
  return 0;
}
