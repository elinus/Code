#include <iostream>
#include <vector>

class Graph {
    private:
        int V, E;
        std::vector<int> *adj;
    public:
        Graph(int v = 0, int e = 0)
            : V(v), E(e), adj(new std::vector<int>[V])
        {}
        
        ~Graph() {
            delete [] adj;
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printAdjList() {
            for (int i = 0; i < V; ++i) {
                std::cout << i << " : ";
                for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << "\n";
            }
        }
};

int main(int argc, char const *argv[]) {
    
    int vertex, edge, src, des;
    std::cin >> vertex >> edge;
    
    Graph gObj(vertex, edge);
    
    for (int i = 0; i < edge; i++) {
        std::cin >> src >> des;
        gObj.addEdge(src, des);
    }
    
    gObj.printAdjList();
    return 0;
}

