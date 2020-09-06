#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if (n == 0) {
                return "";
            }
            vector<vector<int> > matrix(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                matrix[i][i] = 1;
            }
            
            int start = 0;
            int max_ = 1;
            
            for (int i = 0; i < n-1; i++) {
                if(s[i] == s[i+1]) {
                    matrix[i][i+1] = 1;
                    max_ = 2;
                    start = i;
                }
            }

            for (int k = 3; k <= n; k++) {
                for (int i = 0; i < n-k+1; i++) {
                    int j = i + k - 1;
                    if (matrix[i+1][j-1] && s[i] == s[j]) {
                        matrix[i][j] = 1;
                        if (k > max_) {
                            max_ = k;
                            start = i;
                        }
                    }
                }
            }
            cout << s.substr(start, max_) << endl;
            return "";
        }
};

int main (int argc, char const *argv[])
{
    Solution obj;
    string s;
    cin >> s;
    obj.longestPalindrome(s);
    return 0;
}

