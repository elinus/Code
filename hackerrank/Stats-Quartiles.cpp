#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
    cin >> N;
    vector<int> X(N);
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    int rem = N%2;
    int quo = N/2;

    sort(X.begin(), X.end());
    
    if(N % 2 == 0){ // Median
        if(quo%2 == 0){
            cout << (X[quo/2 - 1] + X[quo/2])/2 << endl;
            cout << (X[N/2 - 1] + X[N/2])/2 << endl;
            cout << (X[N/2 + quo/2 - 1] + X[N/2 + quo/2])/2 << endl;
        } else {
            cout << X[N/4] << endl;
            cout << (X[N/2 - 1] + X[N/2])/2 << endl;
            cout << X[N/2 + quo/2] << endl;
        }
	} else {
        cout << (X[N/4 - 1] + X[N/4])/2 << endl;
		cout << X[N/2] << endl;
        cout << (X[3*N/4] + X[3*N/4 + 1])/2 << endl;
	}
	return 0;
}
