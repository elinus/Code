/* Sunil Mourya */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int length = s.size();
    int count = 0;
    int i = 0; 
    while(i < length){
        if(s[i] != 'S'){
            count++;
        }
        i++;
        if(s[i] != 'O'){
            count++;
        }
        i++;
        if(s[i] != 'S'){
            count++;
        }
        i++;
    }
    cout << count << endl;
    return 0;
}

