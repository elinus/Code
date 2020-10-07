#include <iostream>
#include <stack>

using namespace std;

bool balancedBrackets(string str) {
    stack<char> stack_;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] != '(' || str[i] != '{' || str[i] != '[') {
            stack_.push(str[i]);
        } else if (str[i] == ')') {
            char ch;
            while(!stack_.empty()) {
                ch = stack_.top();
                if (ch != '(' || ch != '{' || ch != '[') {
                    stack_.pop();
                    break;
                }
            }
            if (ch == '(') stack_.pop();
        } else if (str[i] == ']') {
            char ch;
            while(!stack_.empty()) {
                ch = stack_.top();
                if (ch != '(' || ch != '{' || ch != '[') {
                    stack_.pop();
                    break;
                }
            }
            if (ch == '[') stack_.pop();
        } else if (str[i] == '}') {
            char ch;
            while(!stack_.empty()) {
                ch = stack_.top();
                if (ch != '(' || ch != '{' || ch != '[') {
                    stack_.pop();
                    break;
                }
            }
            if (ch == '{') stack_.pop();
        }
        if (stack_.empty()) return true;
        return false;
    }
}


