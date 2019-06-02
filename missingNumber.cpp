class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += i;
        }
        int total_nums = 0;
        for (int i = 0; i < n; ++i)
            total_nums += nums[i];
        return total - total_nums;
    }
};