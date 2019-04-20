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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL)  return NULL;
        TreeNode *ret;
        if (t1 == NULL || t2 == NULL) {
            TreeNode *t = t1 == NULL ? t2 : t1;
            ret = new TreeNode(t->val);
            ret->left = mergeTrees(t->left, NULL);
            ret->right = mergeTrees(t->right, NULL);
        } else {
            ret = new TreeNode(t1->val + t2->val);
            ret->left = mergeTrees(t1->left, t2->left);
            ret->right = mergeTrees(t1->right, t2->right);
        }
        return ret;
    }
};