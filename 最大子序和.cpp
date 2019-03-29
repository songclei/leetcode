#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> f(size);
        f[0] = nums[0];
        for (int i = 1; i < size; ++i) {
        	if (nums[i] + f[i-1] > nums[i])
        		f[i] = nums[i] + f[i-1];
        	else 
        		f[i] = nums[i];
        }
        int maxSum = f[0];
        for (int i = 1; i < size; ++i) {
        	if (f[i] > maxSum)
        		maxSum = f[i];
        }
        return maxSum;
    }
};