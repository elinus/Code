#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *src) {
  map<UndirectedGraphNode *, UndirectedGraphNode *> lookup;
  queue<UndirectedGraphNode *> Q;
  Q.push(src);
  UndirectedGraphNode *node = new UndirectedGraphNode(src->label);
  lookup[src] = node;
  while (!Q.empty()) {
    UndirectedGraphNode *front_node = Q.front();
    Q.pop();
    vector<UndirectedGraphNode *> neighbors_vec = front_node->neighbors;
    for (int i = 0; i < neighbors_vec.size(); i++) {
      if (lookup.find(neighbors_vec[i]) == lookup.end()) {
        UndirectedGraphNode *temp =
            new UndirectedGraphNode(neighbors_vec[i]->label);
        lookup[neighbors_vec[i]] = temp;
        Q.push(neighbors_vec[i]);
      }
      lookup[front_node]->neighbors.push_back(lookup[neighbors_vec[i]]);
    }
  }
  return lookup[src];
}