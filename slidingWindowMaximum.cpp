class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0)  return ret;
        int cur_max = nums[0];
        int max_index = 0;
        for (int i = 1; i < k; ++i) {
            if (nums[i] >= cur_max) {
                cur_max = nums[i];
                max_index = i;
            }
        }
        ret.push_back(cur_max);
        for (int i = 1; i <= n-k; ++i) {
            if (nums[i+k-1] >= cur_max) {
                cur_max = nums[i+k-1];
                max_index = i + k - 1;
            } else {
                if (max_index < i) {
                    cur_max = nums[i];
                    max_index = i;
                    for (int j = 1; j < k; ++j) {
                        if (nums[i+j] >= cur_max) {
                            cur_max = nums[i+j];
                            max_index = i+j;
                        }
                    }
                }
            }
            ret.push_back(cur_max);
        }
        return ret;
    }
};