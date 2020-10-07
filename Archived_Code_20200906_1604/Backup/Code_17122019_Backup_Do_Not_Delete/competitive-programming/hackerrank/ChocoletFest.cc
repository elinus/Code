#include <iostream>
using namespace std;

int main()
{
	int T, N, C, M;
	int eat, wrap, elinus;
	cin >> T;
	while(T--){
		elinus = 0;
		cin >> N >> C >> M;
		eat = wrap = N / C;
		while(wrap >= M){
			eat += (wrap/M);
			elinus = (wrap%M);
			wrap = wrap/M + elinus;
		}
		cout << "#" << eat << endl;
	}
	return 0;
}
