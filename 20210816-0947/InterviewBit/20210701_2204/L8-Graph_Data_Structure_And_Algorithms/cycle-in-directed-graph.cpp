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

  bool dfs_util(int v, vector<bool> &visited, vector<bool> &recur_st) {
    if (!visited[v]) {
      visited[v] = true;
      recur_st[v] = true;
      for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it] && dfs_util(*it, visited, recur_st))
          return true;
        else if (recur_st[*it])
          return true;
      }
    }
    recur_st[v] = false;
    return false;
  }

  bool cyclic() {
    vector<bool> visited(V, false);
    vector<bool> recur_st(V, false);
    for (int v = 0; v < V; v++) {
      if (!visited[v] && dfs_util(v, visited, recur_st))
        return true;
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