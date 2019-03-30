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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int> > ret;
    	if (root == NULL) return ret;
    	int dir = 0;
    	int n = 1;
    	stack<TreeNode *> my_stack;
    	my_stack.push(root);
    	while (n != 0) {
    		vector<int> v;
    		stack<TreeNode *> tmp_stack;
    		n = 0;
    		while (!my_stack.empty()) {
	    		TreeNode *node = my_stack.top();
                my_stack.pop();
	    		v.push_back(node->val);
	    		if (dir == 0) {
	    			if (node->left != NULL) {
	    				tmp_stack.push(node->left);
	    				n++;
	    			}
	    			if (node->right != NULL) {
	    				tmp_stack.push(node->right);
	    				n++;
	    			}
	    		}
	    		else {
	    			if (node->right != NULL) {
	    				tmp_stack.push(node->right);
	    				n++;
	    			}
	    			if (node->left != NULL) {
	    				tmp_stack.push(node->left);
	    				n++;
	    			}
	    		}
	    	}
	    	ret.push_back(v);
	    	my_stack = tmp_stack;
	    	dir = 1 - dir;
    	}
    	return ret;
    }
};