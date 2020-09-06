package coursera_org.AlgorithmsPart1;

public class QuickFind {
    private int[] id;

    public QuickFind(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    boolean connected(int u, int v) {
        return id[u] == id[v];
    }

    public void union(int u, int v) {
        int uid = id[u];
        int vid = id[v];
        for (int i = 0; i < id.length; i++) {
            if (id[i] == uid)
                id[i] = vid;
        }
    }
}
