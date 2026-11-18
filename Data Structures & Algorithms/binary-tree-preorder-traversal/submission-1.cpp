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
    void traverse(vector<int>&res, TreeNode* root){
        if(root==nullptr){
            return;
        }
        res.push_back(root->val);
        traverse(res, root->left);
        traverse(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return{};
        }
        vector<int>res;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* curr = root;
        while(!st.empty()){
            if(curr){
                res.push_back(curr->val);
                st.push(curr->right);
                curr = curr->left;
            }else{
                curr = st.top();
                st.pop();
            }
        }
        return res;
    }   
};