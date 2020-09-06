/* Sunil Mourya */
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int  i = 3, j;
    if(N >= 1){
        cout << 2 << endl;
    }
    for(int count = 2; count <= N;)
    {
        for(j = 2; j <= i-1; ++j){
            if(i%j == 0) break;
        }
        if(i == j){
            cout << i << endl;
            count++;
        }
        i++;
    }
    return 0;
}

