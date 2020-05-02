/* Sunil Mourya */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, a, b;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> n >> a >> b;
        int mini = (a < b) ? a : b;
        int maxi = (a > b) ? a : b;
        int delta = maxi - mini;
        int curr = mini * (n - 1);
        cout << curr << " ";
        if(delta > 0){
            for(int i = 0; i < n-1; ++i){
                curr += delta;
                cout << curr << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

