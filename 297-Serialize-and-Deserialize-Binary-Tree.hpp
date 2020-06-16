#include<string>
#include<queue>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res("[");
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            const int level_size = q.size();
            const int res_size = res.size();
            int cnt = 0;
            for(int i = 0;i < level_size;++i){
                TreeNode* node = q.front();
                q.pop();
                if(!node){
                    res += "null,";
                    continue;
                }
                res += to_string(node->val);
                res.push_back(',');

                ++cnt;
                q.push(node->left);
                q.push(node->right);
            }
            if(!cnt)
                res.resize(res_size);
        }
        if(res.back() == ',')
            res.back() = ']';
        else res.push_back(']');
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 2 || data.front() != '[' || data.back() != ']') return nullptr;

        const int end = data.size() - 1;
        int index = 1;

        TreeNode* root = deserialize(data, index, end);
        if(index >= end) return root;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            const int level_size = q.size();
            for(int i = 0; i < level_size; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(!node) continue;
                node->left = deserialize(data, index, end);
                if(index >= end) break;
                q.push(node->left);
                
                node->right = deserialize(data, index, end);
                if(index >= end) break;

                q.push(node->right);
            }
        }
        return root;
    }
private:
    TreeNode* deserialize(const string &data,int& index,int end){
        for(; index < end && isspace(data[index]); ++index){}
        if(index >= end) return nullptr;
        TreeNode *node = nullptr;

        if(isdigit(data[index]) || data[index] == '+' || data[index] == '-'){
            const int val = atoi(&data[index]);
            node = new TreeNode(val);
        }

        for(; index < end && data[index] != ','; ++index){}
        ++index;
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
