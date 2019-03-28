#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > ret;
    	int size = nums.size();
        quickSort(nums, 0, size-1);
        for (int i = 0; i < size-2; ++i) {
        	if (i != 0 && nums[i] == nums[i-1])  continue;
    		vector<int> tup(3);
        	int j = i + 1;
        	int k = size - 1;
        	while (j < k) {
	        	if (nums[i] + nums[j] + nums[k] == 0) {
	        		tup[0] = nums[i];
	        		tup[1] = nums[j];
	        		tup[2] = nums[k];
	        		ret.push_back(tup);
		        	while (j < k && nums[j] == nums[j+1]) j++;
		        	while (j < k && nums[k] == nums[k-1]) k--;
	        		j++; k--;
	        	}
	        	else if (nums[i] + nums[j] + nums[k] < 0) j++;
	        	else k--;
	        }
        }
        return ret;
        
    }

    void quickSort(vector<int>& nums, int left, int right) {
    	int i = left;
    	int j = right;
    	if (i >= j)  return;
    	int pivot = nums[i];
    	while(i < j) {
    		while (j > i && nums[j] >= pivot) 
    			j--;
    		if (j > i) {
    			nums[i] = nums[j];
    			i++;
    		}
    		while (j > i && nums[i] <= pivot)
    			i++;
    		if (j > i) {
    			nums[j] = nums[i];
    			j--;
    		}
    	}
    	nums[i] = pivot;	
    	quickSort(nums, left, i-1);
    	quickSort(nums, i+1, right);
    }
};

int main() {
	Solution solu;
	vector<int> nums;
	
}
