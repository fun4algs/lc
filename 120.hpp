class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.back().size();
        int dp[n];
        memset(dp, 0, sizeof dp);
        for(int i = 0;  i < triangle.back().size(); ++i) dp[i] = triangle.back()[i]; 
        // vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j <= i; ++j)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
        return dp[0];
    }
};
