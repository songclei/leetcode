class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return -1;
        if (n == 1)  return 0;
        if (n == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid+1])  return mid;
                else left = mid + 1;
            } else if (mid == n - 1) {
                if (nums[mid] > nums[mid-1])  return mid;
                else right = mid - 1;
            } else {
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])  return mid;
                else if (nums[mid] > nums[mid-1])  left = mid + 1;
                else if (nums[mid] > nums[mid+1])  right = mid - 1;
                else  left = mid + 1;
            }
        }
        return left;
    }
    
}; 

