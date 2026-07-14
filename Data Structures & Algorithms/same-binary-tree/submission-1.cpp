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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>>myq;
        myq.push({p,q});
        while(!myq.empty()){
            pair<TreeNode*,TreeNode*>curr = myq.front();
            myq.pop();
            if(!curr.first && !curr.second){
                continue;
            }
            if(curr.first && curr.second && curr.first->val == curr.second->val){
                myq.push({curr.first->left,curr.second->left});
                myq.push({curr.first->right,curr.second->right});
            }else{
                return false;
            }        
        }
        return true;
    }
};
