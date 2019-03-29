#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return -1;
        if (nums[0] < nums[size-1]) {
        	return binarySearch(nums, 0, size-1, target);
        }
        else 
        	return rotateBinarySearch(nums, 0, size-1, target);
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
    	cout << "binarySearch " << l << " " << r << endl;
    	if (l > r) return -1;
    	int mid = (l + r) / 2;
    	if (nums[mid] == target)
    		return mid;
    	else if (nums[mid] < target)
    		return binarySearch(nums, mid+1, r, target);
    	else 
    		return binarySearch(nums, l, mid-1, target);
    }

    int rotateBinarySearch(vector<int>& nums, int l, int r, int target) {
    	cout << "rotateBinarySearch " << l << " " << r << endl;
    	if (l > r) return -1;
    	if (nums[l] < nums[r]) return binarySearch(nums, l, r, target);
    	int mid = (l + r) / 2;
    	if (target == nums[mid]) return mid;
    	if (target == nums[l]) return l;
    	if(target == nums[r]) return r;
    	if (target > nums[l]) {
    		if (target < nums[mid]) {
    			return binarySearch(nums, l, mid-1, target);
    		}
    		else {
    			if (nums[mid] > nums[l])
    				return rotateBinarySearch(nums, mid+1, r, target);
    			else 
    				return rotateBinarySearch(nums, l, mid-1, target);
    		}
    	}
    	else if (target < nums[r]) {
    		if (target < nums[mid]) {
  				if (nums[mid] < nums[r]) 
    				return rotateBinarySearch(nums, l, mid-1, target);
    			else 
    				return rotateBinarySearch(nums, mid+1, r, target);
    		}
    		else
    			return rotateBinarySearch(nums, mid+1, r, target);
    	}
    	else {
    		return -1;
    	}
    }
};

int main() {
	Solution solu;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	int target;
	cin >> target;
	cout << solu.search(nums, target) << endl;
	return 0;
}