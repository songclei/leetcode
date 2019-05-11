class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        int i = 0;
        int j = 0;
        int cur_num = nums[0];
        while (j < n) {
            while (j < n && nums[j] == cur_num) j++;
            if (j < n) {
                cur_num = nums[j];
                nums[++i] = cur_num;
            }
        }
        return i+1;
    }
};