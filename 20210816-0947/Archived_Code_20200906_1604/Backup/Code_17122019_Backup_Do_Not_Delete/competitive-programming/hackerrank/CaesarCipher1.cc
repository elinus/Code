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
    int N;
    string S;
    int K;
    cin >> N >> S >> K;
    for(int i = 0; i < N; ++i){
        if(isalpha(S[i])){
            int ch = isupper(S[i]) ? 'A' : 'a';
            int index = S[i] - ch;
            S[i] = ch + (index + K) % 26;
        }
    }
    cout << S << endl;
    return 0;
}

