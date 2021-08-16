#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(int V, int E = 0) : V(V), E(E), adjList(new list<int>[V]) {}
  ~Graph() { delete[] adjList; }
  void addEdge(int u, int v) { adjList[u].push_back(v); }
  bool checkCycle() {
    vector<bool> visited(V), recr(V);
    for (int v = 0; v < V; v++) {
      if (!visited[v] && dfsCycle(v, visited, recr))
        return true;
    }
    return false;
  }

  vector<int> courseSchedule() {
    vector<bool> visited(V);
    stack<int> s;
    vector<int> course_order;
    for (int v = 0; v < V; v++) {
      if (!visited[v]) {
        topologicalSort(v, visited, s);
      }
    }
    if (s.size() != V) {
      return course_order;
    } else {
      while (!s.empty()) {
        course_order.push_back(s.top());
        s.pop();
      }
    }
    return course_order;
  }

private:
  bool dfsCycle(int v, vector<bool> &visited, vector<bool> &recr) {
    if (!visited[v]) {
      visited[v] = true;
      recr[v] = true;
      for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        if (!visited[*it] && dfsCycle(*it, visited, recr))
          return true;
        else if (recr[*it])
          return true;
      }
    }
    recr[v] = false;
    return false;
  }

  void topologicalSort(int v, vector<bool> &visited, stack<int> &s) {
    visited[v] = true;
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
      if (!visited[*it]) {
        topologicalSort(*it, visited, s);
      }
    }
    s.push(v);
  }
  int V, E;
  list<int> *adjList;
};

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    Graph g(numCourses);
    for (int e = 0; e < prerequisites.size(); e++) {
      g.addEdge(prerequisites[e][0], prerequisites[e][1]);
    }
    if (g.checkCycle())
      return {};
    return g.courseSchedule();
  }
};