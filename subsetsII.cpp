class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>().swap(ans);
        vector<int> unique_num;
        unordered_map<int, int> num_cnt;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (num_cnt.count(nums[i]) == 0) {
                unique_num.push_back(nums[i]);
                num_cnt[nums[i]] = 1;
            } else {
                num_cnt[nums[i]]++;
            }
        }
        _subset(unique_num, num_cnt, 0);
        return ans;
    }
    
    void _subset(vector<int>& unique_num, unordered_map<int, int> &num_cnt, int i) {
        int n = unique_num.size();
        if (i == n) {
            ans.push_back(vector<int>());
            return;
        }
        _subset(unique_num, num_cnt, i+1);
        int l = ans.size();
        for (int j = 0; j < l; ++j) {
            vector<int> tmp = ans[j];
            for (int k = 0; k < num_cnt[unique_num[i]]; ++k) {
                tmp.push_back(unique_num[i]);
                ans.push_back(tmp);
            }
        }
    }
};