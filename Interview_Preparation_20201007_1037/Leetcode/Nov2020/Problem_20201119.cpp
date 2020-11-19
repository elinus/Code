#include <bits/stdc++.h>

class Solution {
    public:
        std::string decodeString(std::string s) {
            std::stack<int> sInt;
            std::stack<char> sChar;
            std::string temp = "", result = "";
            for (int i = 0; i < s.size(); ++i) {
                int count = 0;
                if (s[i] >= '0' && s[i] <= '9') {
                    while (s[i] >= '0' && s[i] <= '9') {
                        count = count * 10 + s[i] - '0';
                        i++;
                    }
                    i--;
                    sInt.push(count);
                } else if (s[i] == ']') {
                    temp = "";
                    count = 0;
                    if (!sInt.empty()) {
                        count = sInt.top();
                        sInt.pop();
                    }
                    while (!sChar.empty() && sChar.top() != '[') {
                        temp = sChar.top() + temp;
                        sChar.pop();
                    }
                    if (!sChar.empty() && sChar.top() == '[')
                        sChar.pop();
                    for (int j = 0; j < count; j++) {
                        result += temp;
                    }
                    for (int j = 0; j < result.size(); j++) {
                        sChar.push(result[j]);
                    }
                    result = "";
                } else if (s[i] == '[') {
                    if (s[i-1] >= '0' && s[i-1] <= '9')
                        sChar.push(s[i]);
                    else {
                        sChar.push(s[i]);
                        sInt.push(1);
                    }
                } else {
                    sChar.push(s[i]);
                }
            }
            while (!sChar.empty()) {
                result = sChar.top() + result;
                sChar.pop();
            }
            return result;
        }
};

int main (int argc, const char *argv[]) {
    Solution obj;
    std::cout << obj.decodeString("3[a]2[bc]") << "\n\n";
    std::cout << obj.decodeString("3[a2[c]]") << "\n\n";
    std::cout << obj.decodeString("2[abc]3[cd]ef") << "\n\n";
    std::cout << obj.decodeString("abc3[cd]xyz") << "\n\n";
    return 0;
}

