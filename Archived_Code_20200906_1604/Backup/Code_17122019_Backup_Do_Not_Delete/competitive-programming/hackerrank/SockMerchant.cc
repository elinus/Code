/* 
 *  @file SockMerchant.cc
 *  @author Sunil Mourya
 *  @date 30/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/sock-merchant 
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(200,0);
    int pair = 0;
    int ci;
    for(int i = 0; i < n; ++i){
        cin >> ci;
        if(c[ci] == 0){
            c[ci] += 1;
        } else if(c[ci] == 1){
            c[ci] -= 1;
            pair++;
        }
    }
    cout << pair << endl;
    return 0;
}

