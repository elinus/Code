
/* 
 *  @file TwoStrings.cc
 *  @author Sunil Mourya
 *  @date 25/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/two-strings
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string a, b;
    int la, lb;
    int alphabet[26];
    while(T--){
        cin >> a;
        cin >> b;
        la = a.size();
        lb = b.size();
        for(int i = 0; i < 26; ++i){
            alphabet[i] = 0;
        }
        string output = "NO";
        for(int i = 0; i < la; ++i){
            if(a[i] - 'a'){
                alphabet[a[i] - 'a'] = 1;
            }
        }

        for(int i = 0; i < lb; ++i){
            if(alphabet[b[i] - 'a']){
                output = "YES";
            }
        }

        cout << output << endl;
    }
    return 0;
}

