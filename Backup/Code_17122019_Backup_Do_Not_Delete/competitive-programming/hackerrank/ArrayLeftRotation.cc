/* Sunil Mourya */
#include <bits/stdc++.h>

using namespace std;

void PrintVector(vector<int> &vect){
    copy(vect.begin(),vect.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> vect(n);
    for(int i = 0; i < n; ++i){
        cin >> vect[i];
    }
    int actualRot = d % n;
    vector<int> leftRot(n);
    for(int i = 0; i < n; ++i){
        leftRot[(n - actualRot + i) % n] = vect[i];
    }
    PrintVector(leftRot);
    return 0;
}

