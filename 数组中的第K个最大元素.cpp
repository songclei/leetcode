#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size()-1, k);
    }
	
	int find(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[l];
        int i = l;
        int j = r;
        cout << i << " " << j << endl;
        while (i < j) {
        	while (j > i && nums[j] <= pivot) {
        		j--;
        	}
        	if (j > i) 
        		nums[i] = nums[j];
        	while (j > i && nums[i] >= pivot) {
        		i++;
        	} 
        	if (j > i)
        		nums[j] = nums[i];
        }
        nums[i] = pivot;
        if (i - l == k - 1)
        	return nums[i];
        else if (i - l < k - 1) 
        	return find(nums, i+1, r, k-i+l-1);
        else 
        	return find(nums, l, i-1, k);
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
	int k;
	cin >> k;
	cout << solu.findKthLargest(nums, k) << endl;
	return 0;
}