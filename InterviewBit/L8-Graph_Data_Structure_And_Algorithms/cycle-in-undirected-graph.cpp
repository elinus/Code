#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  Graph(int V) : V{V}, adj{new list<int>[V]} {}
  ~Graph() { delete[] adj; }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool dfs_util(int v, vector<bool> &visited, int parent) {

    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
      if (!visited[*it]) {
        if (dfs_util(*it, visited, v))
          return true;
      } else if (*it != parent)
        return true;
    }
    return false;
  }

  bool cyclic() {
    vector<bool> visited(V, false);
    for (int v = 0; v < V; v++) {
      if (!visited[v]) {
        if (dfs_util(v, visited, -1))
          return true;
      }
    }
    return false;
  }

private:
  int V;
  list<int> *adj;
};

int /* Solution:: */ solve(int A, vector<vector<int>> &B) {
  Graph g(A);
  for (int e = 0; e < B.size(); ++e) {
    g.add_edge(B[e][0] - 1, B[e][1] - 1);
  }
  return g.cyclic();
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
