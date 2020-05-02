/*
 * 125. Valid Palindrome
 * https://leetcode.com/problems/valid-palindrome/
 **/
#include <iostream>
#include <ctype.h>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int len = s.size();
        for (int i = 0, j = len - 1; i < j;) {
            while (i < len && !isalnum(s[i])) {
                i++;
            }
            while (j >= 0 && !isalnum(s[j])) { 
                j--;
            }
            if (i < len && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }
            if (j >= 0 && s[j] >= 'A' && s[j] <= 'Z') {
                s[j] = tolower(s[j]);
            }
            if (i < len && j >= 0 && (int)s[i] != (int)s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sobj;
    std::cout << sobj.isPalindrome("race a car") << "\n";
    std::cout << sobj.isPalindrome("A man, a plan, a canal: Panama") << "\n";
    std::cout << sobj.isPalindrome("") << "\n";
    std::cout << sobj.isPalindrome(".,") << "\n";
    return 0;
}

