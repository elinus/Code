#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--){
		long int A, B, sq, count = 0, sqr = 0;
		cin >> A >> B;
		sq = sqrt(A);
		//if(sq == 1){ sq += 1; }
		sqr = sq * sq;
		while(sqr <= B){
			if(sqr >= A){
				count++;
			}
			sq += 1;
			sqr = sq * sq;
		}
		cout << count << endl;
	}
	return 0;
}
