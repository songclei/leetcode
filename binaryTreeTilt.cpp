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
    int tilt;
public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        tiltAndSum(root);
        return tilt;
    }
    
    int tiltAndSum(TreeNode* root) {
        if (root == 0)  return 0;
        int left = tiltAndSum(root->left);
        int right = tiltAndSum(root->right);
        tilt += abs(left - right);
        return left + right + root->val;
    }
};