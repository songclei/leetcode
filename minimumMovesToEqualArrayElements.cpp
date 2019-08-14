class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min_num = nums[0];
        for (int i = 1; i < n; ++i)  min_num = min(min_num, nums[i]);
        int cnt = 0;
        for (int i = 0; i < n; ++i)  cnt += nums[i] - min_num;
        return cnt;
    }
};