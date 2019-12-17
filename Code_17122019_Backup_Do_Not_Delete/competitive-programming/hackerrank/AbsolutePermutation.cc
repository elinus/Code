
/* 
 *  @file AbsolutePermutation.cc
 *  @author Sunil Mourya
 *  @date 28/10/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/absolute-permutation
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void permutation(int level, vector<int> &perm, vector<int> &marked, int N){
    if(level == N){
        for(int i = 0; i < N; ++i){
            cout << perm[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < N; ++i){
        if(marked[i]){
            marked[i]--;
            perm[level] = i+1;
            permutation(level+1,perm,marked,N);
            marked[i]++;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int N, K;
    while(T--){
        cin >> N >> K;
        vector<int> perm(N);
        vector<int> marked(N,1);
        permutation(0,perm,marked,N);
    }
    return 0;
}

