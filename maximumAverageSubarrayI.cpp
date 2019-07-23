class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long total = 0;
        int i = k - 1;
        for (int j = 0; j <= i; ++j) {
            total += nums[j];
        }
        long max_total = total;
        while (i < n - 1) {
            i++;
            total += nums[i];
            total -= nums[i-k];
            max_total = max(max_total, total);
        }
        return max_total * 1.0 / k;
    }
};