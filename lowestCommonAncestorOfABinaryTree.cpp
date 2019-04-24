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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        int i = path_p.size() - 1;
        int j = path_q.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path_p[i] != path_q[j]) return path_p[i+1];
            i--;
            j--;
        }
        return path_p[i+1];
    }
    
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root == NULL)  return false;
        if (root == p) {
            path.push_back(root);
            return true;
        }
        if (findPath(root->left, p, path)) {
            path.push_back(root);
            return true;
        }
        if (findPath(root->right, p, path)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
};