#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

// class Graph {
// public:
//   Graph(int V, int E = 0) : V(V), E(E), adjList(new list<int>[V]) {}
//   ~Graph() { delete[] adjList; }
//   void addEdge(int u, int v) { adjList[u].push_back(v); }

// private:
//   int V, E;
//   list<int> *adjList;
// };

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> out(N + 1, 0);
    vector<int> in(N + 1, 0);
    for (int e = 0; e < trust.size(); e++) {
      in[trust[e][0]]++;
      out[trust[e][1]]++;
    }
    int judge = -1;
    int count = 0;
    for (int n = 0; n < N; n++) {
      if (!in[n]) {
        judge = n;
      }
      count += in[n];
    }
    if (out[judge] == count)
      return judge;
    return -1;
  }
};