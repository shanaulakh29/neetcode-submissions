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
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*>myq;
        myq.push(root);
        while(!myq.empty()){
            TreeNode* currentNode=myq.front();
            myq.pop();
            if(currentNode!=nullptr){
            TreeNode* temp=currentNode->left;
            currentNode->left=currentNode->right;
            currentNode->right=temp;
            myq.push(currentNode->left);
            myq.push(currentNode->right);
            }
        
        }
        return root;

    }

};
