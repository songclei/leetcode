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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)  return ans;
        vector<TreeNode*> nodeList;
        nodeList.push_back(root);
        while (nodeList.size() != 0) {
            vector<TreeNode*> tmpNode;
            vector<int> tmpVal;
            for (auto it = nodeList.begin(); it != nodeList.end(); ++it) {
                tmpVal.push_back((*it)->val);
                if ((*it)->left)  tmpNode.push_back((*it)->left);
                if ((*it)->right)  tmpNode.push_back((*it)->right);
            }
            ans.insert(ans.begin(), tmpVal);
            nodeList = tmpNode;
        }
        return ans;
    }
};