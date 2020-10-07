/* Sunil Mourya */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<int> query;
    stack<int> max;
    max.push(0);
    int num;
    int type;
    for(int i = 0; i < N; ++i){
        cin >> type;
        if(type == 1){
            cin >> num;
            query.push(num);
            if(num >= max.top()){
                max.push(num);
            }
        } else if(type == 2){
            int t;
            if(!query.empty()){
                t = query.top();
                query.pop();
            }

            if(!max.empty() && t == max.top()){
                max.pop();
            }
        } else if(type == 3){
            cout << max.top() << endl;
        }
    }
    return 0;
}

