/* Sunil Mourya */
#include <iostream>

using namespace std;

int ABS(char x, char y){
    if(x > y)
        return x - y;
    else
        return y - x;
}

int main()
{
    int T;
    cin >> T;
    string s;
    int length;
    for(int t = 1; t <= T; t++){
        cin >> s;
        length = s.size();
        bool funny = true;
        for(int i = 1, j = length-1; i < length && j >= 1; ++i, --j){
            if(ABS(s[i],s[i-1]) != ABS(s[j],s[j-1])){
                funny = false;
                break;
            }
        }
        if(funny){
            cout << "Funny" << endl;
        } else {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}

