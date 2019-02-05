/* Sunil Mourya */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string input;
    stack<char> S;
    stack<char> RS;
    cin >> input;
    for(int i = 0; i < input.size(); ++i){
        if(S.empty() || (!S.empty() && S.top() != input[i])){
            S.push(input[i]);
        } else if(!S.empty() && S.top() == input[i]){
            S.pop();
        }
    }
    if(!S.empty()){
        while(!S.empty()){
            RS.push(S.top());
            S.pop();
        }
        while(!RS.empty()){
            cout << RS.top();
            RS.pop();
        }
        cout << endl;
    } else {
        cout << "Empty String" << endl;
    }
    return 0;
}

