/* Sunil Mourya */
#include <bits/stdc++.h>

using namespace std;

bool kaprekar_present = false;

void check_kaprekar(long int n)
{
    int dig = 0;
    long int sqr = n * n;
    long int elinus = n;
    while(n){
        dig++;
        n /= 10;
    }
    long int half = pow(10,dig);
    long int right = sqr / half;
    long int left = sqr % half;
    if(right + left == elinus){
        cout << elinus << " ";
        kaprekar_present = true;
    }
}

int main()
{
    long int p, q;
    cin >> p >> q;
    for(long int n = p; n <= q; n++)
    {
        check_kaprekar(n);
    }

    if(!kaprekar_present){
        cout << "INVALID RANGE";
    }
    cout << endl;
    return 0;
}

