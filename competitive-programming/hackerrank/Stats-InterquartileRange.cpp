#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double calculateMedian(vector<int> &v, int start, int end){
	int len = end - start + 1;
	if(len%2){
		return v[start + len/2];
	} else {
		return (v[start + len/2 - 1] + v[start+len/2])/2;
	}
}

int main(){
	int N;
    cin >> N;
    vector<int> Xi(N);
    vector<int> Fi(N);
    
    for(int i = 0; i < N; i++){
        cin >> Xi[i];
    }

    int size = 0;
	for(int i = 0; i < N; i++){
        cin >> Fi[i];
        size += Fi[i];
    }
	
    vector<int> X(size);
    int k = 0;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < Fi[i]; j++){
    		X[k++] = Xi[i];
    	}
    }
	N = size;
    int quo = N/2;

    sort(X.begin(), X.end());
    
	double Q1, Q3;
	if(N%2){
		Q1 = calculateMedian(X, 0, quo-1);
		Q3 = calculateMedian(X, quo+1, N-1);
	} else {
		Q1 = calculateMedian(X, 0, quo-1);
		Q3 = calculateMedian(X, quo, N-1); 
	}
	
	cout << fixed << setprecision(1) << (double)(Q3 - Q1) << endl;
	return 0;
}
