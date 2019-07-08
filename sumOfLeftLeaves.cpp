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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == NULL)  return sum;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while (!my_queue.empty()) {
            TreeNode *node = my_queue.front();
            my_queue.pop();
            if (node->left != NULL) {
                if (node->left->left == NULL && node->left->right == NULL)  sum += node->left->val;
                else my_queue.push(node->left);
            }
            if (node->right != NULL)
                my_queue.push(node->right);
        }
        return sum;
    }
};