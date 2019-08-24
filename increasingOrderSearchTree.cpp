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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)  return NULL;
        return (_increasingBST(root)).first;
    }
    
    pair<TreeNode*, TreeNode*> _increasingBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)  return make_pair(root, root);
        else if (root->left == NULL) {
            pair<TreeNode*, TreeNode*> rightPair = _increasingBST(root->right);
            root->right = rightPair.first;
            return make_pair(root, rightPair.second);
        } else if (root->right == NULL) {
            pair<TreeNode*, TreeNode*> leftPair = _increasingBST(root->left);
            (leftPair.second)->right = root;
            root->left = NULL;
            return make_pair(leftPair.first, root);
        } else {
            pair<TreeNode*, TreeNode*> leftPair = _increasingBST(root->left);
            pair<TreeNode*, TreeNode*> rightPair = _increasingBST(root->right);
            (leftPair.second)->right = root;
            root->left = NULL;
            root->right = rightPair.first;
            return make_pair(leftPair.first, rightPair.second);
        }
    } 
};