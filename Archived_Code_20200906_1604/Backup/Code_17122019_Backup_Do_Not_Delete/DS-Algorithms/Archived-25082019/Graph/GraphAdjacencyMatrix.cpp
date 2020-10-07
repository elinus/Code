#include <iostream>
#include <list>
#include <vector>

class Graph {
    public:
        Graph(int V, int E): V(V), E(E) {
            mtx.resize(V, std::vector<int>(V, 0));
        }
        ~Graph() {}
        void addEdge(int u, int v) {
            mtx[u][v] = 1;
        }
        void print() {
            for (int i = 0; i < mtx[0].size(); ++i) {
                for (int j = 0; j < mtx[i].size(); ++j) {
                    std::cout << mtx[i][j] << " ";
                }
                std::cout << "\n";
            }
        }
    private:
        int V; // Vertices
        int E; // Edges
        std::vector<std::vector<int>> mtx;
};


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
    graph.print();
    return 0;
}
