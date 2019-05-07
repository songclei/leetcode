class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)  return 0;
        // for iterator i, sum[j] means the sum of a[j], a[j+1], ..., a[j+i-1]
        vector<int> sum(n);
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n + 1 - i; ++j) {
                sum[j] = sum[j] + nums[j+i-1];
                if (sum[j] == k)  ret++;
            }
        }
        return ret;
    }
};