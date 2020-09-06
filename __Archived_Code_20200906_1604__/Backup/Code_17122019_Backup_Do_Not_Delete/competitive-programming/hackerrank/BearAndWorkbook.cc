#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> noc(n);
	for(int i = 0; i < n; ++i){
		cin >> noc[i];
	}
	int page = 1, special = 0;
	for(int i = 0; i < n; ++i){
		int beg = 1, end;
		if(noc[i] < k){
			end = noc[i];
		} else {
			end = k;
		}
		int nop;
		if(noc[i] % k){
			nop = noc[i]/k + 1;
		} else {
			nop = noc[i] / k;
		}

		int curr = 0;
		while(curr != nop){
			if(page >= beg && page <= end)
				special++;
			curr++;
			page++;
			beg = end + 1;
			noc[i] = noc[i] - k;
			if(noc[i] <= k){
				end = end + noc[i];
			} else {
				end = end + k;
			}
		}
	}
	cout <<  special << endl;
	return 0;
}
