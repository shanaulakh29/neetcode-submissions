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
    TreeNode* invertTree(TreeNode* root) {
        // if(root==nullptr){
        //     return root;
        // }
        // invertTree(root->left);
        // invertTree(root->right);
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        // return root;

        //another ans
        if(root==nullptr){
            return root;
        }
        queue<TreeNode*> myq;
        myq.push(root);
        while(!myq.empty()){
            TreeNode* curr = myq.front();
            myq.pop();
            if(curr){
                TreeNode* temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
                myq.push(curr->left);
                myq.push(curr->right);
            }
        }
        return root;
    }
};
