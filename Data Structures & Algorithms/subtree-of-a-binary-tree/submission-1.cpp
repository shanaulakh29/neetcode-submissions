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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot==nullptr){
            return true;
        }else if(root==nullptr || subRoot==nullptr || root->val!=subRoot->val){
            return false;
        }else if(root->val== subRoot->val){
            return (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right));
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr){
            return true;
        }else if(root==nullptr){
            return false;
        }else if( isSameTree(root, subRoot)){
            return true;
        }
       return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
