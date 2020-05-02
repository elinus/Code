/* 
 *  @author Sunil Mourya
 *  @link https://www.hackerrank.com/challenges/matrix-rotation-algo 
 */

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void print(vector<int> &vect){
    copy(vect.begin(),vect.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<int> > M(R,vector<int>(C,0));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < R; ++i)
        print(M[i]);
    return 0;
}

