class Solution {
public:
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode* node){
        if(node == nullptr) return 0;
        return max(helper(node->left), helper(node->right)) + 1;
    }
};
