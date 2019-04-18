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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, 0, inorder, 0, preorder.size());
    }
    
    TreeNode* _buildTree(vector<int>& preorder, int pre_left, vector<int>& inorder, int in_left, int len) {
        if (len == 0)  return NULL;
        int val = preorder[pre_left];
        int in_loc = find(inorder.begin(), inorder.end(), val) - inorder.begin();
        int left_len = in_loc - in_left;
        int right_len = len - 1 - left_len;
        TreeNode* left = _buildTree(preorder, pre_left+1, inorder, in_left, left_len);
        TreeNode* right = _buildTree(preorder, pre_left+left_len+1, inorder, in_loc+1, right_len);
        TreeNode* ret = new TreeNode(val);
        ret->left = left;
        ret->right = right;
        return ret;
    }
};