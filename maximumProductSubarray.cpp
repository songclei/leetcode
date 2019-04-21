class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        int ret = nums[0];
        int min_pro = 1;
        int max_pro = 1;
        for (int i = 0; i < n; ++i) {
            int produce1 = min_pro * nums[i];
            int produce2 = max_pro * nums[i];
            max_pro = max(nums[i], max(produce1, produce2));
            min_pro = min(nums[i], min(produce1, produce2));
            if (max_pro > ret)
                ret = max_pro;
        }
        return ret;
    }
};