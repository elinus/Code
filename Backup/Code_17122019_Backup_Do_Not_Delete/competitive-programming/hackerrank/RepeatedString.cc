
/* 
 *  @file RepeatedString.cc
 *  @author Sunil Mourya
 *  @date 28/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/repeated-string
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    unsigned long int n;
    cin >> n;

    cout << ((n/s.size()) * count(s.begin(),s.end(),'a')) + count(s.begin(),s.begin() + n%s.size(),'a') << endl;

    return 0;
}

