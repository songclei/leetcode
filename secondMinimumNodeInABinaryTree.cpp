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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL || root->left == NULL)  return -1;
        int left_second = findSecondMinimumValue(root->left);
        int right_second = findSecondMinimumValue(root->right);
        if (root->left->val == root->right->val) {
            if (left_second == -1 && right_second == -1)
                return -1;
            else if (left_second == -1) 
                return right_second;
            else if (right_second == -1)
                return left_second;
            else 
                return min(left_second, right_second);
        } else if (root->left->val > root->right->val) {
            if (right_second == -1)  return root->left->val;
            else return min(right_second, root->left->val);
        } else {
            if (left_second == -1)  return root->right->val;
            else return min(left_second, root->right->val);
        }
    }
};