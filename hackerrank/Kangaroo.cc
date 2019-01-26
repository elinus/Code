
/* 
 *  @file Kangaroo.cc
 *  @author Sunil Mourya
 *  @date 27/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/kangaroo
 */

#include <iostream>

using namespace std;

int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if(v1 > v2 && x1 > x2){
        cout << "NO" << endl;
    } else if(v2 > v1 && x2 > x1){
        cout << "NO" << endl;
    } else {
        int x, y;
        x = x1;
        y = x2;
        bool yes = false;
        while(x < y){
            x += v1;
            y += v2;
            if(x == y){
                yes = true;
                break;
            }
        }

        if(!yes){
            x = x1;
            y = x2;
            while(y < x){
                x += v1;
                y += v2;
                if(x == y){
                    yes = true;
                    break;
                }
            }
        }
        if(yes){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

