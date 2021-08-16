package coursera_org.AlgorithmsPart1;

public class QuickUnion {

    private int[] id;

    QuickUnion(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    private int root(int i) {
        while (id[i] != i) {
            i = id[i];
        }
        return i;
    }

    public boolean connected(int u, int v) {
        return root(u) == root(v);
    }

    public void union(int u, int v) {
        int uid = root(u);
        int vid = root(v);
        id[uid] = vid;
    }
}
