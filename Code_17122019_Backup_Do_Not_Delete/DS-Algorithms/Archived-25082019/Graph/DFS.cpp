#include <iostream>
#include <list>
#include <vector>

class Graph {
    public:
        Graph(int V, int E): V(V), E(E), adj(new std::list<int>[V]) {}
        ~Graph() {
            delete [] adj;
        }
        void addEdge(int u, int v) { adj[u].push_back(v); }
        void dfs(int v) {
            std::vector<bool> marked(V, false);
            dfs_util(v, marked);
        }
        friend std::ostream & operator << (std::ostream & out, const Graph & graph);
    private:
        int V; // Vertices
        int E; // Edges
        std::list<int> *adj;

        void dfs_util(int v, std::vector<bool> &marked) {
            marked[v] = true;
            std::cout << v << " ";
            for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
                if (!marked[*it]) {
                    dfs_util(*it, marked);
                }
            }
        }
};

std::ostream & operator << (std::ostream & out, const Graph & graph) {
    out << "G = (" << graph.V << ", " << graph.E << ")\n";
    for (int v = 0; v < graph.V; ++v) {
        out << v << " : ";
        for (auto it = graph.adj[v].begin(); it != graph.adj[v].end(); ++it) {
            out << *it << " ";
        }
        std::cout << "\n";
    }
    return out;
}

int main(int argc, char const *argv[]) {
    
    Graph graph(7, 9);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 6);
    graph.addEdge(4, 6);
    graph.addEdge(2, 5);
    graph.addEdge(5, 4);
    graph.addEdge(5, 6);

    std::cout << graph << std::endl;
    std::cout << "DFS Traversal:=> ";
    graph.dfs(0);
    std::cout << "\n";

    return 0;
}
