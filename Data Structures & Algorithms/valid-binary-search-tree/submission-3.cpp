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
    bool checkValid(TreeNode* node, int leftValue, int rightValue){
        if(node==nullptr){
            return true;
        }
        if(node->val > leftValue && node->val < rightValue){
            return checkValid(node->left,leftValue, node->val)&& checkValid(node->right, node->val, rightValue);
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return checkValid(root->left, INT_MIN, root->val) && checkValid(root->right, root->val, INT_MAX);

    }
};
