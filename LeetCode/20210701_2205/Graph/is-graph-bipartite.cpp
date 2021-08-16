#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V, int E = 0) : V(V), E(E), adjList(new list<int>[V]) {}
  ~Graph() { delete[] adjList; }
  void addEdge(int u, int v) { adjList[u].push_back(v); }
  bool isBipartite() {
    vector<bool> visited(V);
    vector<int> color(V, -1);

    for (int v = 0; v < V; v++) {
      if (!visited[v]) {
        if (!bfsUtil(v, visited, color))
          return false;
      }
    }
    return true;
  }

private:
  bool bfsUtil(int v, vector<bool> &visited, vector<int> &color) {
    visited[v] = true;
    color[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i) {
        if (!visited[*i]) {
          color[*i] = 1 - color[u];
          visited[*i] = true;
          q.push(*i);
        } else if (color[u] == color[*i]) {
          return false;
        }
      }
    }
    return true;
  }
  int V, E;
  list<int> *adjList;
};

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int N = graph.size();
    Graph g(N);
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < graph[u].size(); v++) {
        g.addEdge(u, graph[u][v]);
      }
    }
    return g.isBipartite();
  }
};
int main() { return 0; }