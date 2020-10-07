/* 
 *  @file DivisibleSumPairs.cc
 *  @author Sunil Mourya
 *  @date 30/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/divisible-sum-pairs 
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i < j && (a[i]+a[j])%k == 0) count++;
        }
    }
    cout << count << endl;           
    return 0;
}

