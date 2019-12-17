
/* 
 *  @file CompareTheTriplets.cc
 *  @author Sunil Mourya
 *  @date 27/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/compare-the-triplets
 */

#include <iostream>

using namespace std;

int main()
{
    int alice = 0, bob = 0; 
    int a0, a1, a2;
    int b0, b1, b2;
    cin >> a0 >> a1 >> a2;
    cin >> b0 >> b1 >> b2;
    if(a0 > b0)
        alice++;
    else if(b0 > a0)
        bob++;

    if(a1 > b1)
        alice++;
    else if(b1 > a1)
        bob++;

    if(a2 > b2)
        alice++;
    else if(b2 > a2)
        bob++;

    cout << alice << " " << bob << endl;
        

    return 0;
}

