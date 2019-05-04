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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> valid_map;
        unordered_map<TreeNode*, int> unvalid_map;
        if (root == NULL)  return 0;
        TreeNode* p = NULL;
        valid_map.insert(make_pair(p, 0));
        unvalid_map.insert(make_pair(p, 0));
        return _rob(root, 1, unvalid_map, valid_map);
    }
    
    int _rob(TreeNode* root, bool valid, unordered_map<TreeNode*, int> &unvalid_map, unordered_map<TreeNode*, int> &valid_map) {
        if (valid == 0 && unvalid_map.count(root) > 0)  return unvalid_map[root];
        if (valid == 1 && valid_map.count(root) > 0)  return valid_map[root];
        int ret;
        if (valid == 0) { 
             ret = _rob(root->left, 1, unvalid_map, valid_map) + _rob(root->right, 1, unvalid_map, valid_map);
            unvalid_map.insert(make_pair(root, ret));
        }
        else {
            ret = max(root->val + _rob(root->left, 0, unvalid_map, valid_map) + _rob(root->right, 0, unvalid_map, valid_map), _rob(root->left, 1, unvalid_map, valid_map) + _rob(root->right, 1, unvalid_map, valid_map));
            valid_map.insert(make_pair(root, ret));
        }
        return ret;
    }
};