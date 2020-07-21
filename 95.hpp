/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : helper(1, n);
    }
    vector<TreeNode*> helper(int m, int n){
        vector<TreeNode*> res;
        if(m > n) { res.push_back(nullptr); return res;}
        for(int i = m; i <= n; ++i){
            auto l = helper(m, i - 1), r = helper(i + 1, n);
            for(auto a : l){
                for(auto b : r){
                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
