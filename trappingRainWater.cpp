class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0 || n == 1 || n == 2)  return 0;
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = right_max[n-1] = 0;
        left_max[1] = height[0];
        right_max[n-2] = height[n-1];
        for (int i = 2; i < n; ++i) 
            left_max[i] = max(height[i-1], left_max[i-1]);
        for (int i = n-3; i >= 0; --i)
            right_max[i] = max(height[i+1], right_max[i+1]);
        
        int area = 0;
        for (int i = 1; i < n-1; ++i) {
            int h = min(left_max[i], right_max[i]);
            if (h <= height[i])  continue;
            area += h - height[i];
        }
        return area;
    }
};