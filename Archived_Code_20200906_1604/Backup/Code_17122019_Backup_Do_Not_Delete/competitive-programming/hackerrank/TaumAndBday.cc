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
    int T;
    long int B, W, X, Y, Z, cost;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> B >> W;
        cin >> X >> Y >> Z;
        cost = 0;
        if(Z < X || Z < Y){
            long int mini, prx, pry, prxy, pryx;
            if(W == B){
                mini = X < Y ? X : Y;
                cost = mini*B + mini*W + Z*W;
            } else {
                mini = W < B ? W : B;
                prx = W*X + B*X + Z*mini; 
                pry = W*Y + B*Y + Z*mini;
                prxy = W*X + B*Y + Z*mini;
                prxy = W*Y + B*X + Z*mini;
                long int arr[4];
                arr[0] = prx;
                arr[1] = pry;
                arr[2] = prxy;
                arr[3] = pryx;
                cost = *min_element(arr,arr+3);
                //if(prx < pry){
                    //cost = prx;
                //} else {
                    //cost = pry;
                //}
            }
        } else {
            cost = B*X + W*Y;
        }
        cout << cost << endl;
    }
    return 0;
}

