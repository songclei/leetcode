/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeMinMax {
    int max;
    int min;
    TreeMinMax *left;
    TreeMinMax *right;
    TreeMinMax(int _max, int _min, TreeMinMax *_left, TreeMinMax *_right) : max(_max), min(_min), left(_left), right(_right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)  return true;
        TreeMinMax* t = buildMinMaxTree(root);
        return _isValidBST(root, t);
    }
    
    TreeMinMax* buildMinMaxTree(TreeNode* root) {
        if (root == NULL)  return NULL;
        TreeMinMax* left = buildMinMaxTree(root->left);
        TreeMinMax* right = buildMinMaxTree(root->right);
        int min_val, max_val;
        if (left == NULL && right == NULL) {
            min_val = root->val;
            max_val = root->val;
        }
        else if (left == NULL) {
            min_val = min(root->val, right->min);
            max_val = max(root->val, right->max);
        }
        else if (right == NULL) {
            min_val = min(root->val, left->min);
            max_val = max(root->val, left->max);
        }
        else {
            min_val = min(root->val, min(right->min, left->min));
            max_val = max(root->val, max(right->max, left->max));
        }
        
        TreeMinMax* t = new TreeMinMax(max_val, min_val, left, right);
        return t;
    }
    
    bool _isValidBST(TreeNode* root, TreeMinMax* t) {
        if (root == NULL)  return true;
        if (!(root->left == NULL || root->val > t->left->max))  return false;
        if (!(root->right == NULL || root->val < t->right->min))  return false;
        return _isValidBST(root->left, t->left) && _isValidBST(root->right, t->right);
    }
};