#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    stack<int> S;
    S.push(0);
    int maxDaysToDie = -1; 
    for (int i = 1; i < N; i++){
        int daysToDie = 1;
        while(!S.empty()){
            if (P[S.top()] >= P[i]){
                daysToDie = max(daysToDie, S.top() + 1);
                S.pop();
            } else {
                break;
            }
        }

        if (S.empty()){
            daysToDie = -1;
        }
        maxDaysToDie = max(maxDaysToDie, daysToDie);
        S.push(i);
    }

    cout << (maxDaysToDie < 0 ? 0 : maxDaysToDie) << endl;
    return 0;

}
