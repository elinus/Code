
/* 
 *  @file CircularArrayRotation.cc
 *  @author Sunil Mourya
 *  @date 27/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/circular-array-rotation
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long n, k, q;
    cin >> n >> k >> q;
    vector<long> input(n);
    for(long i = 0; i < n; ++i){
        cin >> input[i];
    }

    vector<long> rotate(n);   
    for(long i = 0; i < n; ++i){
        rotate[(i+k) % n] = input[i];
    }

    int m;
    for(long i = 0; i < q; ++i){
        cin >> m;
        cout << rotate[m] << endl;
    }
 
    return 0;
}

