class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0)  return 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (nums[i] == val) {
                while (i < j && nums[j] == val) {
                    j--;
                }
                if (i == j)  return i;
                else {
                    nums[i] = nums[j];
                    j--;
                }
            }
            i++;
        }
        if (nums[j] == val)  return j;
        else  return j+1;
    }
};