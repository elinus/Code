#include <bits/stdc++.h>

class Graph {
    private:
    int V, E;
    std::vector<int> *adj;
    void dfsUtil(int v, std::vector<bool>& marked);

    public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        adj = new std::vector<int>[V];
    }
    ~Graph() {
        delete [] adj;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void bfs();
    void bfs(int);
    void dfs();
    void dfs(int);
};

void Graph::bfs() {
    std::vector<bool> marked(V, false);
    std::queue<int> Q;
    for (int v = 0; v < V; v++)  {
        if (!marked[v]) {
            marked[v] = true;
            Q.push(v);
        }
        while (!Q.empty()) {
            int u = Q.front();
            std::cout << u << " ";
            Q.pop();
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                if (!marked[*it]) {
                    marked[*it] = true;
                    Q.push(*it);
                }
            }
        }        
    }
    std::cout << "\n";
}

void Graph::bfs(int v) {
    std::vector<bool> marked(V, false);
    std::queue<int> Q;
    
    marked[v] = true;
    Q.push(v);
        
    while (!Q.empty()) {
        int u = Q.front();
        std::cout << u << " ";
        Q.pop();
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if (!marked[*it]) {
                marked[*it] = true;
                Q.push(*it);
            }
        }
    }        
    std::cout << "\n";
}


void Graph::dfs() {
    std::vector<bool> marked(V, false);
    std::stack<int> S;
    for (int v = 0; v < V; v++)  {
        if (!marked[v]) {
            marked[v] = true;
            S.push(v);
        }
        while (!S.empty()) {
            int u = S.top();
            std::cout << u << " ";
            S.pop();
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                if (!marked[*it]) {
                    marked[*it] = true;
                    S.push(*it);
                }
            }
        }        
    }
    std::cout << "\n";
}

void Graph::dfsUtil(int v, std::vector<bool>& marked) {
    std::cout << v << " ";
    marked[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!marked[*it]) {
            dfsUtil(*it, marked);
        }
    }
}

void Graph::dfs(int v) {
    std::vector<bool> marked(V, false);
    dfsUtil(v, marked);
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    Graph graph(4, 6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.bfs();
    graph.bfs(2);
    graph.dfs();
    graph.dfs(2);

    return 0;
}
