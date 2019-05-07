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
    int max_diameter = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL)  return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if (left_depth + right_depth > max_diameter)
            max_diameter = left_depth + right_depth;
        return max(left_depth, right_depth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)  return 0;
        maxDepth(root);
        return max_diameter;
    }
};