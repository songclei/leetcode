/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        _inorderTraversal(root, ret);
        return ret;
    }
    
    void _inorderTraversal(TreeNode* root, vector<int>& v) {
        if (root == NULL)  return;
        _inorderTraversal(root->left, v);
        v.push_back(root->val);
        _inorderTraversal(root->right, v);
    }
};