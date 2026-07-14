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
    vector<int>res;
    vector<vector<int>>array;
public:
    void dfs(TreeNode* root,int depth){
        if(root==nullptr){
            return;
        }
        if(array.size()==depth){
            array.push_back(vector<int>());
        }
        array[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        for(vector<int>v: array){
            res.push_back(v[v.size()-1]);
        }
        return res;
        // if(root==nullptr){
        //     return res;
        // }
        // queue<TreeNode*> q;
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
        //     res.push_back(subRes[subRes.size()-1]);     
        // }
        // return res;
    }
};
