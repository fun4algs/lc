class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), res = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(),nums.end());
        for(int k = 0;k < n - 2; ++k){
            if(k > 0 && nums[k-1] == nums[k]) continue;
            int i = k + 1, j = n - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(res - target)){
                    res = sum;
                }
                if(sum > target) --j;
                else ++i;
            }
        }
        return res;
    }
};
