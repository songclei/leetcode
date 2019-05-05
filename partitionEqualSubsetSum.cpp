class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return true;
        int sum = 0;
        for (int i = 0; i < n; ++i)  sum += nums[i];
        if (sum % 2 == 1)  return false;
        int target = sum / 2;
        vector<bool> f(target+1);
        for (int i = 0; i <= target; ++i) f[i] = false;
        if (nums[0] <= target) f[nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = target-nums[i]; j >= 1; --j) {
                if (f[j] == true) 
                    f[j+nums[i]] = true;
            }
            f[nums[i]] = true;
        }
        return f[target];
    }

};