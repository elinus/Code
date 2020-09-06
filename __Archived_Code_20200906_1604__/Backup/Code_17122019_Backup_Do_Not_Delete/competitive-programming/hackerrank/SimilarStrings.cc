
/* 
 *  @file SimilarStrings.cpp
 *  @author Sunil Mourya
 *  @date 23/11/2016  
 *  @version 1.0 
 *  @link https://www.hackerrank.com/challenges/similar-strings
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, q, li, ri, length, count;
    bool eq;
    string s;
    cin >> n >> q;
    cin >> s;

    for(int i = 0; i < q; ++i){
        cin >> li >> ri;
        length = ri - li + 1;
        string ss(s.substr(li-1,length));
        vector<vector<int> > sym_eq(length,vector<int>(length,0));
        vector<vector<int> > sym_neq(length,vector<int>(length,0));

        if(length == 1){
            cout << n << endl;
        } else {
            count = 0;
            for(int i = 0; i <= n-length; ++i){
                eq = true;
                string ns(s.substr(i,length));
                vector<vector<int> > sym_eq_eq(length,vector<int>(length,0));
                vector<vector<int> > sym_neq_neq(length,vector<int>(length,0));
                for(int j = 0; j < length; ++j){
                    for(int k = j+1; k < length; ++k){
                        if(ss[j] == ss[k]) sym_eq[j][k] = 1;
                        if(ss[j] != ss[k]) sym_neq[j][k] = 1;
                        if(ns[j] == ns[k]) sym_eq_eq[j][k] = 1;
                        if(ns[j] != ns[k]) sym_neq_neq[j][k] = 1;
                        if(sym_eq[j][k] != sym_eq_eq[j][k] || sym_neq[j][k] != sym_neq_neq[j][k]){
                            eq = false;
                            break;
                        }
                    }
                    if(!eq) break;
                }
                if(eq){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}

