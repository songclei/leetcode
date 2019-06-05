class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || n == 0)  return;
        for (int i = n - 1; i >= n - k; --i) {
            int tmp = nums[n-1];
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        }
    }
};