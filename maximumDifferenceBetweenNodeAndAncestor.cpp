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
    int maxDiff;
public:
    int maxAncestorDiff(TreeNode* root) {
        maxAndMin(root);
        return maxDiff;
    }
    
    vector<int> maxAndMin(TreeNode* root) {
        vector<int> ans(2);
        ans[0] = INT_MAX;
        ans[1] = INT_MIN;
        if (root == NULL) {
            return ans;
        }
        vector<int> left = maxAndMin(root->left);
        vector<int> right = maxAndMin(root->right);
        ans[0] = min(root->val, min(left[0], right[0]));
        ans[1] = max(root->val, max(left[1], right[1]));
        maxDiff = max(maxDiff, max(root->val-ans[0], ans[1]-root->val));
        return ans;
    }
};