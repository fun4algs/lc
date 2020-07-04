class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0;
        int res = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')  ++l;
            else ++r;

            if(l == r) res = max(res, 2 * l);
            else if(r > l){ l = 0; r = 0;}
        }

        l = r = 0;
        for(int i = n - 1; i > 0;--i){
            if(s[i] == '(') ++l;
            else ++r;

            if(l == r) res = max(res, 2 * l);

            else if(l > r){ l = 0; r = 0;}
        }
        return res;
    }
};
