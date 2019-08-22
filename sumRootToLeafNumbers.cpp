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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if (root == NULL)  return 0;
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode *root, int num) {
        int n = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += n;
            return;
        }
        if (root->left) { 
            dfs(root->left, n);
        }
        if (root->right) {
            dfs(root->right, n);
        }
    }
};