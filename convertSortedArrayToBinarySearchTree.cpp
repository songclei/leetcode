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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return NULL;
        return _sortedArrayToBST(nums, 0, n-1);
    }
    
    TreeNode* _sortedArrayToBST(vector<int>&nums, int begin, int end) {
        if (begin > end)  
            return NULL;
        if (begin == end) 
            return new TreeNode(nums[begin]);
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        TreeNode *left = _sortedArrayToBST(nums, begin, mid-1);
        TreeNode *right = _sortedArrayToBST(nums, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};