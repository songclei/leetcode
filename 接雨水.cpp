#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if (length == 0)  return 0;
        vector<int> highest_left(length);
        int max_height = height[0];
        for (int i = 1; i < length; ++i) {
        	if (max_height > height[i])
        		highest_left[i] = max_height;
        	else 
        		max_height = height[i];
        }
        max_height = height[length-1];
        vector<int> highest_right(length);
        for (int i = length - 2; i >= 0; --i) {
        	if (max_height > height[i])
        		highest_right[i] = max_height;
        	else 
        		max_height = height[i];
        }
        int water = 0;
        for (int i = 0; i < length; ++i) {
        	int higher_height = min(highest_right[i], highest_left[i]);
        	if (higher_height > height[i])
        		water += higher_height - height[i];
        }
        return water;
    }
};