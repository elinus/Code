
/* 
 *  @file JumpingOnTheClouds.cc
 *  @author Sunil Mourya
 *  @date 28/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/jumping-on-the-clouds
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> clouds(n);
    for(int i = 0; i < n; ++i){
        cin >> clouds[i];
    }

    int jump = 0;
    for(int i = 0; i < n; ){
        if(i+2 < n && clouds[i+2] == 0){
            i+=2;
            jump++;
            if(i == n-1){
                cout << jump << endl;
                break;
            }
        } else if(i+1 < n && clouds[i+1] == 0){
            i+=1;
            jump++;
            if(i == n-1){
                cout << jump << endl;
                break;
            }
        }
    }
    return 0;
}

