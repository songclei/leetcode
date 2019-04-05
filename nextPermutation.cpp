class Solution {
public :
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return;
        int i;
        for (i = n - 1; i > 0; --i) {
            if (nums[i] > nums[i-1])
                break;
        }
        if (i != 0) {
            int j;
            int min_swap = i;
            for (j = i; j < n; ++j) {
                if (nums[j] > nums[i-1] && nums[j] < nums[min_swap])
                    min_swap = j;
            }
            swap(nums[i-1], nums[min_swap]);
            sort(nums.begin()+i, nums.end());
        } else {
            for (i = 0; i < n / 2; ++i)
                swap(nums[i], nums[n-i-1]);
        }
    }
    
    void swap(int &i, int &j) {
        int tmp = i;
        i = j;
        j = tmp;
    }
};