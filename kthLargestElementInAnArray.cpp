class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return _findKthLargest(nums, 0, n-1, k);
    }
    
    int _findKthLargest(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[l];
        int i = l;
        int j = r;
        while (i < j) {
            while (i < j && nums[j] <= pivot)  j--;
            if (i < j) {
                nums[i] = nums[j];
                i++;
            }
            while (i < j && nums[i] >= pivot) i++;
            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = pivot;
        if (i - l == k - 1)  return nums[i];
        else if (i - l < k - 1)  return _findKthLargest(nums, i+1, r, k-i+l-1);
        else  return _findKthLargest(nums, l, i-1, k);
    }
};