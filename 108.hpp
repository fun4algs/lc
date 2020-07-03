class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>&nums, int l, int r){
        if(l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* p = new TreeNode(nums[mid]);

        p->left = helper(nums, l, mid - 1);
        p->right = helper(nums, mid + 1, r);
        return p;
    }
};
