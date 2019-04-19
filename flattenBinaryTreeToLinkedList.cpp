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
    void flatten(TreeNode* root) {
        _flatten(root);
    }
    
    TreeNode* _flatten(TreeNode* root) {
        if (root == NULL)  return NULL;
        TreeNode* left_last;
        TreeNode* right_last;
        left_last = _flatten(root->left);
        right_last = _flatten(root->right);
        if (left_last == NULL && right_last == NULL)  return root;
        else if (left_last == NULL) {
            return right_last;
        }
        else if (right_last == NULL) {
            root->right = root->left;
            root->left = NULL;
            return left_last;
        }
        else {
            left_last->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return right_last;
        }
    }
    
};