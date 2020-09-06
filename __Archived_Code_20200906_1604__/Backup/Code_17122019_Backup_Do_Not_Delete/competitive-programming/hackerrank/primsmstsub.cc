# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <climits>

using namespace std;

void prim_sum(vector<int> &vect, int s)
{
    int sum = 0;
    for(int i = 0; i < vect.size(); ++i){
        if(i != s){
            if(vect[i] == INT_MAX){
                //cout << "Not reachable " << endl;
            } else {
                sum += vect[i];
            }
        }
    }
    cout << sum <<endl;
}

int min_key(vector<int> &key, vector<bool> &set)
{
    int min = INT_MAX, in;
    for(int i = 0; i < key.size(); ++i){
        if(!set[i] && key[i] <= min){
            min = key[i], in = i;
        }   
    }
    return in;
}

int main()
{
    int N, M, x, y, r, S;
    cin >> N >> M;
    vector<vector<int> > G(N,vector<int>(N,-1));
    for(int i = 0; i < M; ++i){
        cin >> x >> y >> r;
        if(G[x-1][y-1] == -1 || G[x-1][y-1] > r){
            G[x-1][y-1] = G[y-1][x-1] = r;
        }
    }
    for(int i = 0; i < N; ++i){
        G[i][i] = 0;
    }
    cin >> S;
    vector<int> key(N,INT_MAX);
    vector<bool> set(N,false);
    key[S-1] = 0;
    for(int count = 0; count < N-1; ++count){
        int u = min_key(key,set);
        set[u] = true;
        for(int v = 0; v < N; ++v){
            if(!set[v] && G[u][v] != -1 && G[u][v] < key[v]){
                key[v] = G[u][v];
            }
        }
    }
    prim_sum(key,S-1);
    return 0;
}

