class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else return mid;
        }
        return l;
    }
};

//another way
int searchInsert(vector<int>& nums, int target){
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}
