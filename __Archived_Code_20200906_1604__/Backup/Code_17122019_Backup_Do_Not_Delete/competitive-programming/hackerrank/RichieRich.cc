/* 
 *  @author Sunil Mourya
 *  @link https://www.hackerrank.com/challenges/richie-rich 
 */

#include <iostream>
#include <string>

using namespace std;

bool pallind(int s, int e, string &str){
    for(int i = s, j = e; i < j; ++i, --j){
        if(str[i] != str[j]) return false;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int start = 0, end = n-1; 
    if(k == 0 && pallind(start,end,s)){
        cout << s << endl;
    } else if(k > 0 && k%2){
        for(int i = start, j = endl; i < j; ++i, --j){
            if(s[i] != s[j]){
                if(s[i] > s[j])
            }
        }
    } else if(k > 0 && !(k%2)){

    } else {
        cout << "-1" << endl;
    }

    return 0;
}

