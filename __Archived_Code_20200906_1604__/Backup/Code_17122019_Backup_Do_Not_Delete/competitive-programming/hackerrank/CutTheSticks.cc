#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool less_than_1(int n) { return (n < 1); }

int main()
{
	int N;
	cin >> N;
	vector<int> stick(N);
	for(int i = 0; i < N; ++i){
		cin >> stick[i];
	}
	int prev_size = stick.size();
	while(!stick.empty()){
		cout << prev_size << endl;
		int mini = *min_element(stick.begin(),stick.end());
		for(int i = 0; i < stick.size(); ++i){
			stick[i] -= mini;
		}
		stick.erase(remove_if(stick.begin(),stick.end(),less_than_1),stick.end());
		prev_size = stick.size();
	}
	return 0;
}
