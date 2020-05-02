/* Sunil Mourya */
#include <bits/stdc++.h>

using namespace std;

string product(string a, string b)
{
    vector<int> result(a.size()+b.size(),0);
    for(int i = a.size()-1; i >= 0; --i){
        for(int j = b.size()-1; j >= 0; --j){
            result[i+j+1] += (b[j] - '0') * (a[i] - '0');
        }
    }

    for(int i = a.size() + b.size(); i >= 0; --i){
        if(result[i] >= 10){
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    
    int index = 0;
    if(result[0] == 0){
        index++;
    }

    stringstream ss;
    vector<int>::iterator it;
    for(it = result.begin()+index; it != result.end(); ++it){
        ss << *it;
    }
    return ss.str();
}

int main()
{
    int N;
    cin >> N;
    string prod = "1";
    string strIn;
    for(int i = 2; i <= N; ++i){
        stringstream sstrIn;
        sstrIn << i;
        sstrIn >> strIn;
        prod = product(prod,strIn);
    }
    cout << prod << endl; 
    return 0;
}

