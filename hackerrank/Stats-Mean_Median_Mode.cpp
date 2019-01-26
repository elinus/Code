#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> X[i];
        sum += X[i];
    }
    
	cout << fixed;
    cout << setprecision(1);
    cout << (double)sum/N << endl; // Mean
    
    sort(X.begin(), X.end());
    if(X.size() % 2 == 0){ // Median
		cout << (double)(X[X.size()/2 - 1] + X[X.size()/2])/2 << endl;
	} else {
		cout << (double)X[X.size()/2] << endl;
	}
	
	// Mode
	int counter = 1;
    int max = 0;
    int mode = X[0];
    for (int i = 0; i < X.size() - 1; i++){
        if (X[i] == X[i+1] ){
            counter++;
			if (counter > max ){
                max = counter;
                mode = X[i];
            }
        } else
            counter = 1; 
    }
    cout << mode << endl;
    return 0;
}

