/* 
 *  @file Anagram.cc
 *  @author Sunil Mourya
 *  @date 25/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/making-anagrams 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    int l1 = s1.size();
    cin >> s2;
    int l2 = s2.size();
    vector<int> alphabet(26,0);
    for(int i = 0; i < l1; ++i){
        alphabet[s1[i] - 'a']++;
    }
    int count = 0;
    for(int i = 0; i < l2; ++i){
        if(alphabet[s2[i] - 'a']){
            alphabet[s2[i] - 'a']--;
        } else {
            count++;
        }
        
    }

    for(int i = 0; i < 26; ++i){
        if(alphabet[i]){
            count += alphabet[i];
        }
    }
    cout << count << endl;
    return 0;
}

