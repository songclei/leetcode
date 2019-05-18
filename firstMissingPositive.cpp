class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int minPos = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] < minPos)
                minPos = nums[i];
            if (nums[i] == 0)  nums[i] = -1;
        }
        if (minPos > 1)  return 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n)  continue;
            int j = nums[i];
            while (j > 0 && j <= n) {
                int tmp = nums[j-1];
                nums[j-1] = 0;
                j = tmp;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)  return i+1;
        }
        return n+1;
    }
};