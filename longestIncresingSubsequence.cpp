class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        vector<int> f(n);
        int max_length = 1;
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            int max_len = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i])  continue;
                if (f[j] + 1 > max_len)
                    max_len = f[j] + 1;
            }
            f[i] = max_len;
            if (max_length < max_len)
                max_length = max_len;
        }
        return max_length;
    }
};