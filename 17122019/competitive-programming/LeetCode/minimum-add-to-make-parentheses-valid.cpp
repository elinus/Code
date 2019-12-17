class Solution {
    public:
        int minAddToMakeValid(string S) {
            if (S.length() == 0) return 0;
            stack<int> ps;
            for(int i = 0; i < S.length(); i++){
                if(S[i] == '(') {
                    ps.push('(');
                } else if(S[i] == ')' && (ps.empty() || ps.top() == ')')) {
                    ps.push(')');
                } else {
                    ps.pop();
                }
            }
            return ps.size();
        }
};
