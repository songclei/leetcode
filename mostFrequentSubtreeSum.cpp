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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sum_cnt;
        vector<int> ret;
        getSum(root, sum_cnt);
        int most_frequent = 0;
        for (auto it = sum_cnt.begin(); it != sum_cnt.end(); ++it) {
            most_frequent = max(most_frequent, it->second);
        }
        for (auto it = sum_cnt.begin(); it != sum_cnt.end(); ++it) {
            if (it->second == most_frequent) {
                ret.push_back(it->first);
            }
        }
        return ret;
    }
    
    int getSum(TreeNode* root, unordered_map<int, int> &sum_cnt) {
        if (root == NULL)  return 0;
        int left_sum = getSum(root->left, sum_cnt);
        int right_sum = getSum(root->right, sum_cnt);
        int sum = left_sum + right_sum + root->val;
        if (sum_cnt.count(sum) == 0) {
            sum_cnt[sum] = 1;
        } else {
            sum_cnt[sum]++;
        }
        return sum;
    }
};