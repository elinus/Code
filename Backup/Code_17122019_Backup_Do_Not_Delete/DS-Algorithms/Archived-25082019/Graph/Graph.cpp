#include <iostream>
#include <list>
#include <vector>

class Graph {
    public:
        Graph(int V, int E): V(V), E(E), adj(new std::list<int>[V]) {}
        ~Graph() {
            delete [] adj;
        }
        void addEdge(int u, int v) { 
            adj[u].push_back(v); 
        }
        friend std::ostream & operator << (std::ostream & out, const Graph & graph);
    private:
        int V; // Vertices
        int E; // Edges
        std::list<int> *adj;
};

std::ostream & operator << (std::ostream & out, const Graph & graph) {
    out << "G={V(" << graph.V << "), E(" << graph.E << ")}\n";
    for (int v = 0; v < graph.V; ++v) {
        out << v << " : ";
        for (auto it = graph.adj[v].begin(); it != graph.adj[v].end(); ++it) {
            out << *it << " ";
        }
        out << "\n";
        /*
        out << "(indegree = " << graph.adj[v].size() << ")\n";
        */
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
    std::cout << graph;

    return 0;
}
