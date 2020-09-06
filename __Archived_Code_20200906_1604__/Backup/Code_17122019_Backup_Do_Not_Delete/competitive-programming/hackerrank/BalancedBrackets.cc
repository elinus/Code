/* Sunil Mourya */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string brackets;
    char bracketType;

    for(int i = 0; i < N; ++i){
        stack<int> S;
        cin >> brackets;
        for(int j = 0; j < brackets.length(); ++j){
            bracketType = brackets[j];
            if(bracketType == '{' || bracketType == '(' || bracketType == '['){
                S.push(bracketType);
            } else if(S.empty() && (bracketType == '}' || bracketType == ')' || bracketType == ']')){
                S.push(bracketType);
                break;
            } else if(bracketType == '}'){
                if(!S.empty() && S.top() == '{' )
                    S.pop();
            } else if(bracketType == ')'){
                if(!S.empty() && S.top() == '(')
                    S.pop();
            } else if(bracketType == ']'){
                if(!S.empty() && S.top() == '[')
                    S.pop();
            }
        }

        if(S.empty()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

