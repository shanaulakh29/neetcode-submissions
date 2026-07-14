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
    vector<vector<int>>res;
public:
    void dfs(TreeNode* root, int depth){
        if(root==nullptr){
            return;
        }
        if(res.size()==depth){
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {  
        //DFS
        dfs(root,0);
        return res;
        
        
        //BFS
        // vector<vector<int>>res;
        // if(root==nullptr){
        //     return res;
        // }
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size = q.size();
        //     vector<int>subRes;
        //     for(int i=0;i<size;i++){
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         if(curr){
        //             subRes.push_back(curr->val);
        //             if(curr->left){
        //                 q.push(curr->left);
        //             }
        //             if(curr->right){
        //                 q.push(curr->right);
        //             }
        //         }
        //     }
        //     res.push_back(subRes);
        // }
        // return res;
    }
};
