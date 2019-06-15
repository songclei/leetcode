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
    unordered_map<TreeNode*, int> depth;
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)  return true;
        if (root->left == NULL && root->right == NULL) {
            depth.insert(make_pair(root, 1));
            return true;
        }
        if (!isBalanced(root->left) || !isBalanced(root->right)) {
            return false;
        }
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        depth.insert(make_pair(root, max(left_depth, right_depth)+1));
        if (abs(left_depth-right_depth) <= 1)  return true;
        else return false;
    }
    
    int getDepth(TreeNode *root) {
        if (root == NULL)  return 0;
        return depth[root];
    }
};