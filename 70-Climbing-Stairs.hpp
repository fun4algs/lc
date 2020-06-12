//author:Leonhard
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int>dp(n);
        dp[0] = 1,dp[1] = 2;
        for(int i = 2;i < n;++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp.back();
    }
};

//optimization
namespace B{
    class Solution {
        public:
            int climbStairs(int n) {
                long a = 1,b = 1;
                while(n--){
                    b += a;
                    a = b - a;
                }
                return a;
            }
    };
}
