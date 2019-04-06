class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)  return -1;
        return zigBinararySearch(nums, 0, n-1, target);
    }
    
    int binararySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right)  return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target)  return mid;
        else if (nums[mid] > target)  return binararySearch(nums, left, mid-1, target);
        else  return binararySearch(nums, mid+1, right, target);
    }
    
    int zigBinararySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right)  return -1;
        if (nums[left] <= nums[right])  return binararySearch(nums, left, right, target);
        int mid = (left + right) / 2;
        if (nums[mid] == target)  return mid;
        if (nums[right] < target && target < nums[left])  
            return -1;
        else if (nums[left] <= target) {
            if (target < nums[mid])  return binararySearch(nums, left, mid-1, target);
            else if (nums[mid] <= nums[right])  return zigBinararySearch(nums, left, mid-1, target);
            else  return zigBinararySearch(nums, mid+1, right, target);
        }
        else {
            if (target > nums[mid])  return binararySearch(nums, mid+1, right, target);
            else if (nums[mid] <= nums[right])  return zigBinararySearch(nums, left, mid-1, target);
            else  return zigBinararySearch(nums, mid+1, right, target);
        }
    }
};



