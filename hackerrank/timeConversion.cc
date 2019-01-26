#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string time;
    cin >> time;
    int len = time.length();
    int deci = (time[0] - '0') * 10 + (time[1] - '0');
    if(time[8] == 'A'){
	for(int i = 0; i < 8; ++i){
	  cout << time[i];
	}
	cout << endl;
    } else if(deci+12 == 24){
     cout << "12:00:00" << endl;
	} 
else {
	cout << deci+12;
	for(int i = 2; i < 8; ++i){
	  cout << time[i];
        }
       cout << endl;
    }
    return 0;
}

