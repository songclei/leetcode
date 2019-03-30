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
        if (root == p || root == q || root == NULL)
        	return root;
	    else {
	    	int p_dir = findNode(root->left, p) ? 0 : 1;
	    	int q_dir = findNode(root->left, q) ? 0 : 1;
	    	if (p_dir != q_dir)
	    		return root;
	    	else if (p_dir == 0)
	    		return lowestCommonAncestor(root->left, p, q);
	    	else 
	    		return lowestCommonAncestor(root->right, p, q);
	    }
    }
 
    bool findNode(TreeNode* root, TreeNode* t) {
    	if (root == t)
    		return true;
    	if (root == NULL) 
    		return false;
    	else 
    		return findNode(root->left, t) || findNode(root->right, t);
    }
};