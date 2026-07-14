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
        //recursive dfs
        // if(root==nullptr){
        //     return 0;
        // }
        // return 1+max(maxDepth(root->left),maxDepth(root->right));

        //bfs
        // if(root==nullptr){
        //     return 0;
        // }
        // queue<TreeNode*>myq;
        // myq.push(root);
        // int total = 0;
        // while(!myq.empty()){
        //     int size = myq.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* curr = myq.front();
        //         myq.pop();
        //         if(curr){
        //             myq.push(curr->left);
        //             myq.push(curr->right);
        //         }
        //     }
        //     total+=1;
        // }
        // return total-1;

        //iterative dfs
        stack<pair<TreeNode*, int>> st;
        st.push({root,1});
        int total=0;
        while(!st.empty()){
            pair<TreeNode*, int>curr = st.top();
            st.pop();
            if(curr.first){
                total=max(total, curr.second);
                st.push({curr.first->left,curr.second+1});
                st.push({curr.first->right,curr.second+1});
            }
        }
        return total;
    }
};
