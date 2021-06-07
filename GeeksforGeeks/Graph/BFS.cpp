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
  void bfs();
  void bfs(int v, vector<bool> &visited);

private:
  int V;
  list<int> *adj;
};

void Graph::bfs(int v, vector<bool> &visited) {
  queue<int> qu;
  qu.push(v);
  visited[v] = true;
  while (!qu.empty()) {
    int u = qu.front();
    cout << u << " ";
    qu.pop();
    for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        qu.push(*it);
      }
    }
  }
  cout << "\n";
}

void Graph::bfs() {
  vector<bool> visited(V);
  for (int v = 0; v < V; v++) {
    if (!visited[v]) {
      bfs(v, visited);
    }
  }
}

int main(int argc, char const *argv[]) {
  Graph g1(4);
  g1.add_edge(0, 1);
  g1.add_edge(0, 2);
  g1.add_edge(2, 0);
  g1.add_edge(2, 3);
  g1.add_edge(3, 3);
  g1.print();
  g1.bfs();

  Graph g2(5);
  g2.add_edge(0, 1);
  g2.add_edge(0, 2);
  g2.add_edge(1, 2);
  g2.add_edge(1, 4);
  g2.add_edge(2, 3);
  g2.add_edge(3, 4);
  g2.print();
  g2.bfs();

  Graph g3(9);
  g3.add_edge(0, 1);
  g3.add_edge(0, 3);
  g3.add_edge(1, 2);
  g3.add_edge(2, 3);
  g3.add_edge(2, 0);

  g3.add_edge(4, 8);
  g3.add_edge(8, 7);
  g3.add_edge(5, 4);
  g3.add_edge(5, 6);
  g3.add_edge(5, 7);
  g3.add_edge(7, 6);
  //   g3.print();
  return 0;
}
