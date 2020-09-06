package Graph;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class DFS {

    private int V;
    private ArrayList<Integer> adj[];

    DFS(int V) {
        this.V = V;
        adj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    void dfsUtil(int v, boolean marked[]) {
        marked[v] = true;
        System.out.print(v + " ");
        Iterator<Integer> iterator = adj[v].listIterator();
        while (iterator.hasNext()) {
            v = iterator.next();
            if (!marked[v]) {
                dfsUtil(v, marked);
            }
        }
    }

    void dfs(int v) {
        boolean marked[] = new boolean[V];
        dfsUtil(v, marked);
    }

    public static void main(String[] args) {
        DFS dfs = new DFS(4);
        dfs.addEdge(0, 1);
        dfs.addEdge(0, 2);
        dfs.addEdge(1, 2);
        dfs.addEdge(2, 0);
        dfs.addEdge(2, 3);
        dfs.addEdge(3, 3);
        dfs.dfs(2);
    }
}
