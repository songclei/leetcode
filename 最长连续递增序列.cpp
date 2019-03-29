#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    	int size = nums.size();
        int i = 0, j = 0;
        int longestLength = 0;
        while (i < size && j < size) {
        	j = i;
	        while (j < size-1 && nums[j+1] > nums[j]) {
	        	j++;
	        }
	        cout << j << endl;
	        if (j-i+1 > longestLength)
	        	longestLength = j - i + 1;
	        i = j + 1;
	    }
	    return longestLength;
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
	cout << solu.findLengthOfLCIS(nums) << endl;
	return 0;
}

