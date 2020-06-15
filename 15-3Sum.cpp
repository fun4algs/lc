//author:Leonhard
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        const int n = nums.size();
        if(n<3) return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int fi = i+1;
            int bi = n-1;
            while(fi < bi){
                int sum = nums[fi] + nums[bi];
                if(sum < target) ++fi;
                else if(sum > target) --bi;
                else {
                    res.push_back({nums[i],nums[fi],nums[bi]});
                    do{fi++;}while(fi < bi && nums[fi] == nums[fi - 1]);
                    do{bi--;}while(fi < bi && nums[bi] == nums[bi + 1]);
                }
            }
        }
        return res;
    }
};
