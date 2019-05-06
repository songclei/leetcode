class Solution {
    vector<int> sum;
    int _findTargetSumWays(vector<int>& nums, int index, int target) {
        if (index == 0) {
            if (target == 0 && nums[0] == 0)  return 2;
            if (target == -nums[0] || target == nums[0])  return 1;
            else  return 0;
        }
        if (target > sum[index] || target < -sum[index])  return 0;
        return _findTargetSumWays(nums, index-1, target-nums[index]) + _findTargetSumWays(nums, index-1, target+nums[index]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0)  return 0;
        // sum from a0 to ai
        sum.resize(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        return _findTargetSumWays(nums, n-1, S);
    }
};