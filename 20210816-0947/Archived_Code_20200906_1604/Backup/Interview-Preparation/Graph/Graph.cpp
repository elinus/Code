#include <iostream>
#include <vector>
#include <iomanip>

class Graph {
    private:
        int V;
        int E;
        std::vector<int> *adj;
    public:
        Graph(int v, int e)
            : V(v), E(e), adj(new std::vector<int>[V])
        {}

        ~Graph() {
            delete [] adj;
        }

        void AddEdge(int u, int v) {
            adj[u].push_back(v);
        }

        void PrintAdjacencyList() {
            for (int i = 0; i < V; i++) {
                std::cout << std::setw(3) <<  i << "|";
                for (int j = 0; j < adj[i].size(); j++) {
                    std::cout << std::setw(4) << adj[i][j];
                }
                std::cout << "\n";
            }
        }

        void PrintAdjacencyMatrix() {
            std::vector<std::vector<int>> mtx(V, std::vector<int>(V, 0));
            
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < adj[i].size(); j++) {
                    mtx[i][adj[i][j]] = 1;
                }
            }
            
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    std::cout << std::setw(3) << mtx[i][j];
                }
                std::cout << "\n";
            }
        }
};

int main (int argc, char *argv[]) {
    
    int vertex, edge, src, dest;

    std::cin >> vertex >> edge;
    
    Graph gObj(vertex, edge);
    
    for (int i = 0; i < edge; i++) {
        std::cin >> src >> dest;
        gObj.AddEdge(src, dest);
    }

    gObj.PrintAdjacencyList();
    std::cout << "\n\n";
    gObj.PrintAdjacencyMatrix();
    return 0;
}


