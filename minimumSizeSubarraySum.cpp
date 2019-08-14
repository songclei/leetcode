class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int curSum = 0;
        int minimalLen = INT_MAX;
        while (j < n) {
            while (j < n) {
                curSum += nums[j];
                j++;
                if (curSum >= s) {
                    break;
                }
            }
            if (curSum < s)  break;
            while (i <= j) {
                curSum -= nums[i];
                i++;
                if (curSum < s)  break;
            }
            minimalLen = min(minimalLen, j-i+1);
        }
        if (minimalLen == INT_MAX)  return 0;
        else return minimalLen;
    }
};