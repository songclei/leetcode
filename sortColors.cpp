class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return;
        int cnt_red = 0;
        int cnt_white = 0;
        int cnt_blue = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)  cnt_red++;
            if (nums[i] == 1)  cnt_white++;
            if (nums[i] == 2)  cnt_blue++;
        }
        for (int i = 0; i < n; ++i) {
            if (cnt_red > 0) {
                nums[i] = 0;
                cnt_red--;
            } else if (cnt_white > 0) {
                nums[i] = 1;
                cnt_white--;
            } else {
                nums[i] = 2;
                cnt_white--;
            }
        }
    }
};