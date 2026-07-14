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
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        if(curr==nullptr){
            return curr;
        }
        if(p->val < curr->val && q->val < curr->val){
            return lowestCommonAncestor(curr->left,p,q);
        }else if(p->val > curr->val && q->val > curr->val){
            return lowestCommonAncestor(curr->right,p,q);
        }else{
            return curr;
        }
    }
};
        // TreeNode* curr = root;
        // while(curr){
        //     if(p->val < curr->val && q->val < curr->val){
        //         curr=curr->left;
        //     }else if(p->val > curr->val && q->val > curr->val){
        //         curr=curr->right;
        //     }else{
        //         return curr;
        //     }
        // }
        // return curr;