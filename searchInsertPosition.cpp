class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return _searchInsert(nums, 0, n-1, target);
    }
    
    int _searchInsert(vector<int>& nums, int left, int right, int target) {
        // cout << "left: " << left << " ,right: " << right << endl; 
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)  return mid;
        else if (target < nums[mid]) {
            if (mid == left)  return left;
            else if (target > nums[mid-1])  return mid;
            else return _searchInsert(nums, left, mid-1, target);
        } else {
            if (mid == right)  return right+1;
            else if(target < nums[mid+1]) return mid+1;
            else return _searchInsert(nums, mid+1, right, target);
        }
    }
};