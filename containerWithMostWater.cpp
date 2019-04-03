class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (height[j] >= height[i]) {
                    int area = height[i] * (j - i);
                    if (area > max_area)  max_area = area;
                    break;
                }
            }
            for (int j = 0; j <= i; ++j) {
                if (height[j] >= height[i]) {
                    int area = height[i] * (i - j);
                    if (area > max_area)  max_area = area;
                    break;
                }
            }
        }
        return max_area;
    }
};