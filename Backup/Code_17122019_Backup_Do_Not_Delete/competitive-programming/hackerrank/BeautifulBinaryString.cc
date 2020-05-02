/* Sunil Mourya */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string bs;
    cin >> bs;
    int count = 0;
    for(int i = 0; i < N-2; ++i){
        if(bs[i] == '0'){
            if(bs[i+1] == '1'){
                if(bs[i+2] == '0'){
                    bs[i+2] = '1';
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}

