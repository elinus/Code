/* 
 *  @file BonAppetit.cc
 *  @author Sunil Mourya
 *  @date 30/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/bon-appetit
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    int total = 0;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        if(i != k){
            total += c[i];
        }
    }
    int paid;
    cin >> paid;
    if((total/2) == paid){
        cout << "Bon Appetit" << endl;
    } else {
        cout << paid - (total/2) << endl;
    }
    return 0;
}

