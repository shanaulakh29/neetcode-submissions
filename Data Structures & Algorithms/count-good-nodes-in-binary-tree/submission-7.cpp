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
    int dfs(TreeNode*root, int maxValue){
        if(root==nullptr){
            return 0;
        }
        int res=0;
        if(maxValue<=root->val){
            res+=1;
        }
        res+=dfs(root->left, max(maxValue, root->val));
        res+=dfs(root->right, max(maxValue, root->val));
        return res;    
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
