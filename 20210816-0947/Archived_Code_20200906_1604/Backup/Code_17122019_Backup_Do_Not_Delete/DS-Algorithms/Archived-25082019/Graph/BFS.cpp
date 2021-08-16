#include <iostream>
#include <list>
#include <vector>

class Graph {
    public:
        Graph(int V, int E) : V(V), E(E), adj(new std::list<int>[V]) {}

        void addEdge(int u, int v) { adj[u].push_back(v); }

        void bfs(int s) {
            std::vector<bool> marked(V, false);
            std::list<int> qu;

            marked[s] = true;
            qu.push_back(s);
            while (!qu.empty()) {
                s = qu.front();
                std::cout << s << " ";
                qu.pop_front();
                for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
                    if (!marked[*it]) {
                        marked[*it] = true;
                        qu.push_back(*it);
                    }
                }
            }
        }

    private:
        int V;
        int E;
        std::list<int> *adj;
};

int main() {

    Graph g(4, 6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "BFS Traversal: ";
    g.bfs(2);
    std::cout << "\n";

    return 0;
}
