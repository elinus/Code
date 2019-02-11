#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    public:
        Graph(int V) : V(V), adj(new list<int>[V]) 
        {}

        void AddEdge(int u, int v) {
            adj[u].push_back(v);
        }

        void bfs(int s) {
            vector<bool> marked(V, false);
            list<int> Q;

            marked[s] = true;
            Q.push_back(s);
            while (!Q.empty()) {
                s = Q.front();
                cout << s << " ";
                Q.pop_front();
                for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
                    if (!marked[*it]) {
                        marked[*it] = true;
                        Q.push_back(*it);
                    }
                }
            }
        }
    private:
        int V;
        list<int> *adj;
};

int main() {
    
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
    
    cout << "bfs: ";
    g.bfs(2);
    cout << "\n";

    return 0;
}
