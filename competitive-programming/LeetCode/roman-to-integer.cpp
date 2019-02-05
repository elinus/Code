#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10},
                {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            int num = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'I' && i+1 < s.size() && s[i+1]) {
                    
                }
            }
            return 0;
        }
};

int main (int argc, char *argv[])
{
    Solution obj;
    cout << obj.romanToInt("IV") << endl;
    return 0;
}

