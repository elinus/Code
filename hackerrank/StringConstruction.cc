
/* 
 *  @file StringConstruction.cc
 *  @author Sunil Mourya
 *  @date 25/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/string-construction
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string si;
    int length, cost;
    int alphabet[26];
    for(int t = 0; t < T; ++t){
        cin >> si;
        for(int i = 0; i < 26; ++i){
            alphabet[i] = 0;
        }
        length = si.size();
        cost = 0;
        for(int i = 0; i < length; ++i){
            if(alphabet[si[i] - 'a']){ // SKIP
            } else {
                alphabet[si[i] - 'a'] = 1;
                cost++;
            }
        }
        cout << cost << endl;
    }
    return 0;
}

