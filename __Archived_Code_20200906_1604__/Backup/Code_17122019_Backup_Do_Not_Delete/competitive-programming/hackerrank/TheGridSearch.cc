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
    int T, R, C, r, c;
    char ch;
    cin >> T;

    for(int t = 1; t <= T; t++)
    {
        cin >> R >> C;
        vector<vector<int> > G(R,vector<int>(C,0));
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> ch;
                G[i][j] = ch - '0';
            }
        }

        cin >> r >> c;
        vector<vector<int> > P(r,vector<int>(c,0));
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cin >> ch;
                P[i][j] = ch - '0';
            }
        }

        bool found = false;
        for(int gr = 0; gr < R - r; ++gr){
            for(int gc = 0; gc < C - c; ++gc){
                if(G[gr][gc] == P[0][0]){
                    bool wrong = false;
                    for(int pr = 0; pr < r; ++pr){
                        for(int pc = 0; pc < c; ++pc){
                            if(G[gr+pr][gc+pc] != P[pr][pc]){
                                wrong = true;
                            }
                            if(wrong){
                                break;
                            }
                        }
                        if(wrong){
                            break;
                        }
                    }
                    if(!wrong){
                        found = true;
                    }
                }
                if(found){
                    break;
                }
            }
            if(found){
                break;
            }
        }

        if(found){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

