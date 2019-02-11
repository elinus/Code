#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V) : V(V), adj(new list<int>[V]) {}

  void AddEdge(int u, int v) { adj[u].push_back(v); }

  void dfs(int v) {
    vector<bool> marked(V, false);
    list<int> Q;
    dfs_util(v, marked);
  }

private:
  int V;
  list<int> *adj;

  void dfs_util(int v, vector<bool> &marked) {
    marked[v] = true;
    cout << v << " ";
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
      if (!marked[*it]) {
        dfs_util(*it, marked);
      }
    }
  }
};

int main() {

  Graph g(4);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(1, 2);
  g.AddEdge(2, 0);
  g.AddEdge(2, 3);
  g.AddEdge(3, 3);

  cout << "dfs: ";
  g.dfs(2);
  cout << "\n";

  return 0;
}
