class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            if(S == "" && T == "") return true;
            stack<char> ss;
            stack<char> ts;
            for(int i = 0; i < S.length(); ++i) {
                if(S[i] != '#') {
                    ss.push(S[i]);
                } else {
                    if(!ss.empty()) ss.pop();
                }
            }
            for(int i = 0; i < T.length(); ++i) {
                if(T[i] != '#') {
                    ts.push(T[i]);
                } else {
                    if(!ts.empty()) ts.pop();
                }
            }
            while(!ss.empty() && !ts.empty()) {
                if(ss.top() != ts.top()) return false;
                if(!ss.empty()) ss.pop();
                if(!ts.empty()) ts.pop();
            }
            if(!ss.empty() || !ts.empty()) return false;
            return true;
        }
};
