class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return;
        int non_zero = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)  nums[non_zero++] = nums[i];
        }
        for (int i = non_zero; i < n; ++i)
            nums[i] = 0;
    }
};