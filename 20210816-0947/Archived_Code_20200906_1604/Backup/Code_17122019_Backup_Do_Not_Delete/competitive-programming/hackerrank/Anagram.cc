/* 
 *  @file Anagram.cc
 *  @author Sunil Mourya
 *  @date 25/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/anagram
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int length, count;
    string s;
    while(T--){
        cin >> s;
        length = s.size();
        if(length%2){
            cout << "-1" << endl;
        } else {
            string s1(s.substr(0,length/2));
            int l1 = s1.size();
            string s2(s.substr(length/2, length));
            int l2 = s2.size();
            vector<int> alphabet(26,0);
            for(int i = 0; i < l1; ++i){
                alphabet[s1[i] - 'a']++;
            }
            for(int i = 0; i < l2; ++i){
                if(alphabet[s2[i] - 'a']){
                    alphabet[s2[i] - 'a']--;
                }
            }
            count = 0;
            for(int i = 0; i < 26; ++i){
                if(alphabet[i]){
                    count += alphabet[i];
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}

