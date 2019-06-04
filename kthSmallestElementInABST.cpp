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
    unordered_map<TreeNode*, int> nodeCnt;
public:
    int kthSmallest(TreeNode* root, int k) {
        int lessCnt = nodeCount(root->left);
        if (lessCnt == k - 1)  return root->val;
        else if (lessCnt > k - 1) 
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k-lessCnt-1);
    }
    
    int nodeCount(TreeNode *root) {
        if (root == NULL)  return 0;
        if (nodeCnt.count(root) != 0)
            return nodeCnt[root];
        int cnt = 1 + nodeCount(root->left) + nodeCount(root->right);
        nodeCnt[root] = cnt;
        return cnt;
    }
};