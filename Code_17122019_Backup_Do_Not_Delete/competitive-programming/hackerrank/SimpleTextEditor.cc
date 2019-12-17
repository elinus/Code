/* Sunil Mourya */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int Q;
    stack<string> Ss;
    string S = "";
    string W;
    int k;
    Ss.push(S);
    for(int i = 0; i < N; ++i){
        cin >> Q;
        if(Q == 1){
            cin >> W;
            S = Ss.top() + W;
            Ss.push(S);
        } else if(Q == 2){
            cin >> k;
            string topS = Ss.top();
            int len = topS.length();
            string newS = topS.substr(0,len-k);
            Ss.push(newS);
        } else if(Q == 3){
            cin >> k;
            string topS = Ss.top();
            cout << topS[k-1] << endl;
        } else if(Q == 4){
            Ss.pop();
        }
    }
    return 0;
}

