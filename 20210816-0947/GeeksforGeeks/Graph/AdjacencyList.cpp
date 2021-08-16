#include <bits/stdc++.h>
using namespace std;

// Adjacency List
struct AdjListNode {
  int dest;
  struct AdjListNode *next;
};

struct AdjList {
  struct AdjListNode *head;
};

struct Graph {
  int V;
  struct AdjList *array;
};

AdjListNode *create_node(int dest) {
  AdjListNode *node = new AdjListNode;
  node->dest = dest;
  node->next = nullptr;
  return node;
}

struct Graph *create_graph(int v) {
  Graph *graph = new Graph;
  graph->V = v;
  graph->array = new AdjList[v];
  for (auto i = 0; i < v; i++) {
    graph->array[i].head = nullptr;
  }
  return graph;
}

void add_edge(Graph *graph, int src, int dest, bool is_digraph = true) {
  if (!graph)
    return;
  AdjListNode *node = create_node(dest);
  node->next = graph->array[src].head;
  graph->array[src].head = node;
  if (!is_digraph) {
    node = create_node(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
  }
}

void print_graph(Graph *graph) {
  for (int v = 0; v < graph->V; v++) {
    cout << v << " |= ";
    AdjListNode *curr = graph->array[v].head;
    while (curr) {
      cout << curr->dest << " ";
      curr = curr->next;
    }
    cout << "\n";
  }
}

int main(int argc, char const *argv[]) {
  int v = 5;
  struct Graph *graph = create_graph(v);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 4);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  print_graph(graph);
  return 0;
}
