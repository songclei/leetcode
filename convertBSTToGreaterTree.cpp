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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)  return root;
        set<int, greater<int>> val_set;
        unordered_map<int, int> sum_map;
        // travel the tree and get every val
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while (!my_queue.empty()) {
            TreeNode *tmp = my_queue.front();
            my_queue.pop();
            val_set.insert(tmp->val);
            if (tmp->left)  my_queue.push(tmp->left);
            if (tmp->right)  my_queue.push(tmp->right);
        }
        // caculate sum greater than the node 
        int sum = 0;
        for (auto it = val_set.begin(); it != val_set.end(); ++it) {
            sum += *it;
            sum_map.insert(make_pair(*it, sum));
            //cout << *it << " " << sum << endl;
        }
        // travel the tree and update
        my_queue.push(root);
        while (!my_queue.empty()) {
            TreeNode *tmp = my_queue.front();
            my_queue.pop();
            tmp->val = sum_map[tmp->val];
            if (tmp->left)  my_queue.push(tmp->left);
            if (tmp->right)  my_queue.push(tmp->right);
        }
        return root;
    }
};