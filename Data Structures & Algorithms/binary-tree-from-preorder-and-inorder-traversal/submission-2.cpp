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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() && inorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(), inorder.end(), root->val)-inorder.begin();
        vector<int> leftinorder = vector<int>(inorder.begin(), inorder.begin()+mid);
        vector<int>leftpreorder = vector<int>(preorder.begin()+1, preorder.begin()+mid+1);

        vector<int> rightinorder = vector<int>(inorder.begin()+mid+1, inorder.end());
        vector<int> rightpreorder = vector<int>(preorder.begin()+mid+1, preorder.end());

        TreeNode* left = buildTree(leftpreorder, leftinorder);
        TreeNode* right = buildTree(rightpreorder, rightinorder);
        root->left = left;
        root->right=right;
        return root;

    }
};
