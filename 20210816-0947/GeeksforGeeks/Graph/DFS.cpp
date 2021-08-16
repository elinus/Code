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
  void dfs();
  void dfs(int v, vector<bool> &visited);
  void dfs_recur(int v, vector<bool> &visited);

private:
  int V;
  list<int> *adj;
};

void Graph::dfs(int v, vector<bool> &visited) {
  stack<int> st;
  st.push(v);
  visited[v] = true;
  while (!st.empty()) {
    int u = st.top();
    cout << u << " ";
    st.pop();
    for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        st.push(*it);
      }
    }
  }
}

void Graph::dfs_recur(int v, vector<bool> &visited) {
  visited[v] = true;
  cout << v << " ";
  for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
    if (!visited[*it])
      dfs_recur(*it, visited);
  }
}

void Graph::dfs() {
  vector<bool> visited(V);
  for (int v = 0; v < V; v++) {
    if (!visited[v]) {
      dfs(v, visited);
      //   dfs_recur(v, visited);
    }
  }
  cout << "\n\n";
}

int main(int argc, char const *argv[]) {
  Graph g1(4);
  g1.add_edge(0, 1);
  g1.add_edge(0, 2);
  g1.add_edge(2, 0);
  g1.add_edge(2, 3);
  g1.add_edge(3, 3);
  g1.print();
  g1.dfs();

  Graph g2(5);
  g2.add_edge(0, 1);
  g2.add_edge(0, 2);
  g2.add_edge(1, 2);
  g2.add_edge(1, 4);
  g2.add_edge(2, 3);
  g2.add_edge(3, 4);
  g2.print();
  g2.dfs();

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
  g3.print();
  g3.dfs();
  return 0;
}
