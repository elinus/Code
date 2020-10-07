/* Sunil Mourya */
#include <bits/stdc++.h>

using namespace std;

string getInWords(int h, int m)
{
    string lookup[] = { "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine", 
        "ten", "eleven", "twelve", "thirteen", "fourteen", 
        "fifteen", "sixteen", "seventeen", "eighteen", "ninteen", 
        "twenty", "twenty one", "twenty two", "twenty three", "twenty four", 
        "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine" };

    if(m == 0){
        return lookup[h] + " o' clock";
    }
    if (m == 1){
        return lookup[m] + " minute past " + lookup[h];
    }
    if ((1<m && m<15) || (15<m &&m <30)){
        return lookup[m] + " minutes past " + lookup[h];
    }
    if (m == 15){
        return "quarter past " + lookup[h];
    }
    if (m == 30){
        return "half past " + lookup[h];
    }
    if ((30<m && m<45) || (45<m && m<59)){
        return lookup[60-m] + " minutes to " + lookup[(h+1)%24];
    }
    if (m == 45){
        return "quarter to " + lookup[(h+1)%24];
    }
    if (m == 59){
        return lookup[60-m] + " minute to " + lookup[(h+1)%24];
    }
    return "ERROR";
}

int main()
{
    int h, m;
    cin >> h >> m ;
    string time = getInWords(h,m);
    cout << time << endl;
    return 0;
}
