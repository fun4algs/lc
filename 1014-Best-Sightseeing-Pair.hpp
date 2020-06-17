//author:Leonhard
#include<vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        const int n = A.size();
        int res = 0, cur_max = A[0];

        for(int i = 1;i < n; ++i){
            res = max(res, cur_max + A[i] - i);
            cur_max = max(cur_max, A[i] + i);
        }
        return res;
    }
};
