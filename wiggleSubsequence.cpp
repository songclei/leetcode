class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)  return n;
        vector<int> f1(n);
        vector<int> f2(n);
        int max_len = 1;
        f1[0] = 1;
        f2[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f1[i] = max(f2[j] + 1, f1[i]);
                }
                if (nums[j] > nums[i]) {
                    f2[i] = max(f1[j]+1, f2[i]);
                }
            }
            max_len = max(max_len, f1[i]);
            max_len = max(max_len, f2[i]);
        }
        return max_len;
    }
};