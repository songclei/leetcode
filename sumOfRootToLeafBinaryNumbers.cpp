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
    int sum;
public:
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        if (root == NULL)  return 0;
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode *root, int s) {
        s = s * 2 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += s;
            return;
        }
        if (root->left) dfs(root->left, s);
        if (root->right) dfs(root->right, s);
    }
};