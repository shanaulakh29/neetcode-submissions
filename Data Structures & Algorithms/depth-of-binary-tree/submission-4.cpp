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
    int maxDepth(TreeNode* root) {
        // if(root==nullptr){
        //     return 0;
        // }
        // return 1+max(maxDepth(root->left),maxDepth(root->right));
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>myq;
        myq.push(root);
        int total = 0;
        while(!myq.empty()){
            int size = myq.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = myq.front();
                myq.pop();
                if(curr){
                    myq.push(curr->left);
                    myq.push(curr->right);
                }
            }
            total+=1;
        }
        return total-1;
    }
};
