
/* 
 *  @file PalindromeIndex.cc
 *  @author Sunil Mourya
 *  @date 25/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/palindrome-index
 */

#include <iostream>
#include <string>

using namespace std;

bool check_pallin(int start, int end, const string &str){
    for(int i = start, j = end; i < j; ++i, --j){
        if(str[i] != str[j])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    string s;
    int length;
    while(t--){
        cin >> s;
        length = s.size();
        if(check_pallin(0,length-1,s)){
            cout << "-1" << endl;
        } else {
            int current, first, last;
            first = 0;
            last = length - 1;
            while(first < last){
                if(s[first] != s[last]){
                    first++;
                    if(check_pallin(first,last,s)){
                        cout << first - 1 << endl;
                        break;
                    }
                    first--;
                    last--;
                    if(check_pallin(first,last,s)){
                        cout << last + 1 << endl;
                        break;
                    }
                } else {
                    first++;
                    last--;
                }
            }
        }
    }
    
    return 0;
}

