class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)  return false;
        vector<bool> smaller_before(n);
        vector<bool> larger_after(n);
        int min_num = nums[0];
        for (int i = 1; i < n; ++i) {
            if (min_num < nums[i]) smaller_before[i] = true;
            if (min_num > nums[i]) min_num = nums[i];
        }
        int max_num = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if (max_num > nums[i]) larger_after[i] = true;
            if (max_num < nums[i]) max_num = nums[i];
        }
        for (int i = 1; i < n - 1; ++i) {
            if (smaller_before[i] && larger_after[i])  return true;
        }
        return false;
    } 
};