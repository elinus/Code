/* 
 *  @author Sunil Mourya
 *  @date 06/11/2016
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print(vector<int> &vect){
    copy(vect.begin(),vect.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ai(n);
    for(int i = 0; i < n; ++i)
        cin >> ai[i];
    sort(ai.begin(),ai.end());
    vector<int> bi(m);
    for(int i = 0; i < m; ++i)
        cin >> bi[i];
    sort(bi.begin(),bi.end());

    int count = 0;
    bool factor = true;
    for(int i = ai[n-1]; i <= bi[0]; ++i){
        factor =  true;
        for(int j = 0;  j < n; ++j){
            if(i%ai[j]){
                factor = false;
                break;
            }
        }
        if(factor){
            for(int j = 0; j < m; ++j){
                if(bi[j]%i){
                    factor = false;
                    break;
                }
            }
        }
        if(factor) count++;
    }
    cout << count << endl;
    return 0;
}

