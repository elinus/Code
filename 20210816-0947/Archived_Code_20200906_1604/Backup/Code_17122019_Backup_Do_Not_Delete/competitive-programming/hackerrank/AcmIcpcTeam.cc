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

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char ch;
    vector<vector<int> > team(N,vector<int>(M,0));
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; ++m){
            cin >> ch;
            team[n][m] = ch - '0';
        }
    }
    int max_by_two = 0, no_team = 0;
    vector<int> elinus;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            int know = 0;
            for(int k = 0; k < M; ++k){
                if(team[i][k] || team[j][k]){
                    know++;
                }
            }
            elinus.push_back(know);
            if(know > max_by_two){
                max_by_two = know;
            }
        }
    }
    vector<int>::iterator it;
    for(it = elinus.begin(); it != elinus.end(); ++it){
        if(*it == max_by_two){
            ++no_team;
        }
    }
    cout << max_by_two << endl;
    cout << no_team << endl;
    return 0;
}

