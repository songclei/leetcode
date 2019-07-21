class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ordered_height = heights;
        sort(ordered_height.begin(), ordered_height.end());
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            if (heights[i] != ordered_height[i])  ans++;
        }
        return ans;
    }
};