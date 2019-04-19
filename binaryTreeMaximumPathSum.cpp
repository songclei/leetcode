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
    int maxPathSum(TreeNode* root) {
        if (root == NULL)  return 0;
        int max_sum = root->val;
        _maxPathSum(root, max_sum);
        return max_sum;
    }
    
    int _maxPathSum(TreeNode* root, int &max_sum) {
        if (root == NULL)  return 0;
        int sum;
        int left_sum = _maxPathSum(root->left, max_sum);
        int right_sum = _maxPathSum(root->right, max_sum);
        if (left_sum > right_sum) {
            if (left_sum > 0)  {
                sum = left_sum + root->val;
                if (right_sum > 0 && sum + right_sum > max_sum)
                    max_sum = sum + right_sum;
                else if (right_sum <= 0 && sum > max_sum)
                    max_sum = sum;
            }
            else {
                sum = root->val;
                if (sum > max_sum)  max_sum = sum;
            }
        }
        else {
            if (right_sum > 0) {
                sum = right_sum + root->val;
                if (left_sum > 0 && left_sum + sum > max_sum)
                    max_sum = sum + left_sum;
                else if (left_sum <= 0 && sum > max_sum)
                    max_sum = sum;
            }
            else {
                sum = root->val;
                if (sum > max_sum)  max_sum = sum;
            }
        }
        return sum;
    }
};