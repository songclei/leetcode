class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = binarySearch(nums, 0, n-1, target);
        // 没有大于等于target的数，或找到了，但这个数严格大于target
        if (left == -1 || nums[left] != target) {
            vector<int> ret = {-1, -1};
            return ret;
        }
        int right = binarySearch(nums, left, n-1, target+1);
        // 如果没有找到比target大的数，说明所有的数都小于等于target
        if (right == -1) {
            vector<int> ret = {left, n-1};
            return ret;
        }
        else {
            vector<int> ret = {left, right-1};
            return ret;
        }
    }
    
    // 找到第一个大于等于target的数
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        if (l > r)  return -1;
        int mid = (l + r) / 2;
        if (nums[mid] >= target) {
            if (mid == 0)  return mid;
            else if (nums[mid-1] < target)  return mid;
            else  return binarySearch(nums, l, mid-1, target);
        }
        else 
            return binarySearch(nums, mid+1, r, target);
    }
};