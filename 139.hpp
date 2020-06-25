class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>_us;
        for(string w : wordDict) _us.insert(w);
        int n = s.size();
        vector<bool>dp(n + 1,false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                string str = s.substr(j, i - j);
                if(dp[j] && _us.find(str) != _us.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
