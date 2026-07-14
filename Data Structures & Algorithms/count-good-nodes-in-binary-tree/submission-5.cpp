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
    int dfs(TreeNode* root,int maxVal){
        if(root==nullptr){
            return 0;
        }
        int res= root->val>=maxVal?1:0;
        maxVal = max(maxVal, root->val);
        res += dfs(root->left,maxVal);
        res += dfs(root->right, maxVal);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);

        //bfs
    //     queue<pair<TreeNode*, int>>q;
    //     int res=0;
    //     q.push({root,root->val});
    //     while(!q.empty()){
    //         pair<TreeNode*, int> curr = q.front();
    //         q.pop();
    //         if(curr.first){
    //             res+=curr.first->val>=curr.second?1:0;
    //             int maxVal = max(curr.second, curr.first->val);
    //             if(curr.first->left){
    //                 q.push({curr.first->left, maxVal});
    //             }
    //             if(curr.first->right){
    //                 q.push({curr.first->right, maxVal});
    //             }

    //         }
    //     }
    //     return res; 
     }
};
