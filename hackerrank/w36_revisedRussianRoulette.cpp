#include <bits/stdc++.h>

using namespace std;

vector<int> revisedRussianRoulette(vector<int>& doors) {
    vector<int> result(2);
    int cons = 0;
    int mini = 0;
    int maxi = 0;
    for(int i = 0; i < doors.size(); i++){
    	if(doors[i] == 1) maxi++;
	}
	
	for(int i = 0; i < doors.size(); i++){
    	if((i+1) < doors.size() && doors[i] == 1 && doors[i+1] == 1) doors[i+1] = 0;
	}
	
	for(int i = 0; i < doors.size(); i++){
    	if(doors[i] == 1) mini++;
	}
	
	result[0] = mini;
	result[1] = maxi;
	return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> doors(n);
    for(int doors_i = 0; doors_i < n; doors_i++){
       cin >> doors[doors_i];
    }
    vector<int> result = revisedRussianRoulette(doors);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}

