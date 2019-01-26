/* Sunil Mourya */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int cc = 1;
    cin >> S;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] >= 'A' && S[i] <= 'Z'){
            cc++;
        }
    }
    cout << cc << endl;
    return 0;
}

