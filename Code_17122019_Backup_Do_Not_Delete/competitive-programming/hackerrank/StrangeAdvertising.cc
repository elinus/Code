/* 
 *  @file StrangeAdvertising.cc
 *  @author Sunil Mourya
 *  @date 30/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/strange-advertising
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int start = 5;
    int like = 0;
    int total = 0;
    for(int i = 0; i < n; ++i){
        like = start / 2;
        total += like;
        start = like * 3;
    }
    cout << total << endl;
    return 0;
}

