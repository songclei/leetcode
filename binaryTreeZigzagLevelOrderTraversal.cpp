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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)  return ret;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        int n = 1;
        int d = 0;
        while (n > 0) {
            vector<int> tmp;
            int cnt = 0;
            while (n > 0) {
                TreeNode *node = my_queue.front();
                my_queue.pop();
                n--;
                tmp.push_back(node->val);
                if (node->left != NULL) {
                    my_queue.push(node->left);
                    cnt++;
                }
                if (node->right != NULL) {
                    my_queue.push(node->right);
                    cnt++;
                }
            }
            n = cnt;
            if (d == 1)  reverse(tmp.begin(), tmp.end());
            d = 1 - d;
            ret.push_back(tmp);
        }
        return ret;
    }
};