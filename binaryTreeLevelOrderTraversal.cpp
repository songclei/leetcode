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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)  return ret;
        queue<pair<TreeNode*, int>> my_queue;
        int cur_level = 0;
        my_queue.push(make_pair(root, 1));
        vector<int> tmp;
        while (!my_queue.empty()) {
            TreeNode* node = my_queue.front().first;
            int level = my_queue.front().second;
            my_queue.pop();
            if (level > cur_level) {
                if (cur_level > 0)  ret.push_back(tmp);
                vector<int>().swap(tmp);
                cur_level++;
            }
            tmp.push_back(node->val);
            if (node->left != NULL)  
                my_queue.push(make_pair(node->left, level+1));
            if (node->right != NULL)
                my_queue.push(make_pair(node->right, level+1));
        }
        ret.push_back(tmp);
        return ret;
    }
};