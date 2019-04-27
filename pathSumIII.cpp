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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)  return 0;
        int ret = 0;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while (!my_queue.empty()) {
            int total = 0;
            TreeNode *tmp = my_queue.front();
            dfs(tmp, sum, total);
            ret += total;
            my_queue.pop();
            if (tmp->left != NULL)  my_queue.push(tmp->left);
            if (tmp->right != NULL)  my_queue.push(tmp->right);
        }
        return ret;
    }
    
    void dfs(TreeNode* root, int sum, int &ret) {
        if (root == NULL)  return;
        if (root->val == sum)  ret++;
        dfs(root->left, sum-root->val, ret);
        dfs(root->right, sum-root->val, ret);
    }
};