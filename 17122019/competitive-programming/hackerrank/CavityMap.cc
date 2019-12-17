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

void print(vector<char> vect)
{
    copy(vect.begin(),vect.end(),ostream_iterator<char>(cout,"")); cout << endl;
}

int main()
{
    int n;
    string s;
    cin >> n;
    vector<vector<char> > matrix(n,vector<char>(n,'0'));
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < n; ++j){
            matrix[i][j] = s[j];
        }
    }
    int xdir[] = {1, 0, -1, 0};
    int ydir[] = {0, 1, 0, -1};
    for(int i = 1; i < n-1; ++i){
        for(int j = 1; j < n-1; ++j){
            int check = 0;
            for(int k = 0; k < 4; ++k){
                if(matrix[i+xdir[k]][j+ydir[k]] < matrix[i][j]){
                    check++;
                }
                if(check == 4){
                    matrix[i][j] = 'X';
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        print(matrix[i]);
    }
    return 0;
}

