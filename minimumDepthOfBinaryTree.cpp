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
    int minDepth(TreeNode* root) {
        if (root == NULL)  return 0;
        queue<pair<TreeNode*, int> > my_queue;
        my_queue.push(make_pair(root, 1));
        while (!my_queue.empty()) {
            TreeNode *tmp = my_queue.front().first;
            int height = my_queue.front().second;
            my_queue.pop();
            if (tmp->left == NULL && tmp->right == NULL)  return height;
            if (tmp->left) 
                my_queue.push(make_pair(tmp->left, height+1));
            if (tmp->right)  
                my_queue.push(make_pair(tmp->right, height+1));
        }
        return 0;
    }
};