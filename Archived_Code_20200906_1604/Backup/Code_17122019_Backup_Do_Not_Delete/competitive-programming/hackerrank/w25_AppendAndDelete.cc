/* 
 *  @author Sunil Mourya
 *  @date 06/11/2016  
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int k, slen, tlen;
    cin >> k;
    slen = s.size();
    tlen = t.size();
    int same = 0;
    int mini = slen < tlen ? slen : tlen;
    for(int i = 0; i < mini; ++i){
        if(s[i] != t[i]) 
            break;
        same++;
    }

    cout << same << endl;
    return 0;
}

