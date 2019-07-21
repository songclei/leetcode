class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long cur_pro = nums[0];
        int cnt = 0;
        while (i < n && j < n) {
            if (cur_pro < k) {
                cnt++;
                j++;
                if (j < n)  cur_pro *= nums[j];
            } else {
                i++;
                if (j < i) {
                    j = i;
                    if (i < n)  cur_pro = nums[i];
                } else {
                    cnt += j - i;
                    cur_pro /= nums[i-1];
                }
            }
        }
        while (i < n) {
            if (cur_pro < k) {
                i++;
                cnt += j - i;
                cur_pro /= nums[i-1];
            }
        }
        return cnt;
    }
};