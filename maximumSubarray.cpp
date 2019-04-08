class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return n;
        int max_sum = nums[0];
        int current_sum = 0;
        for (int i = 0; i < n; ++i) {
            int sum = current_sum + nums[i];
            if (sum < nums[i])
                current_sum = nums[i];
            else 
                current_sum = sum;
            if (current_sum > max_sum)  max_sum = current_sum;
        }
        return max_sum;
    }
};