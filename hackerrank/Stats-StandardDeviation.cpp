#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> v(N);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	double mean = (double)sum/N;
	double sqr_dist = 0;
	for (int i = 0; i < N; ++i)
	{
		sqr_dist += ((v[i] - mean) * (v[i] - mean)); 
	}
	cout << fixed << setprecision(1) << sqrt(sqr_dist/N) << endl;
	return 0;
}
