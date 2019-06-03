class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return;
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums);
        int i = n / 2 + (n % 2) - 1;
        int j = n - 1;
        int k = 0;
        while (k < n) {
            if (k < n)  nums[k++] = tmp[i--];
            if (k < n)  nums[k++] = tmp[j--];
        }
    }
};