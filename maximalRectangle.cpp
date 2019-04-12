class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)  return 0;
        int n = matrix[0].size();
        vector<int> heights(n);
        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else 
                    heights[j]++;
                //cout << heights[j] << " ";
            }
            //cout << endl;
            int local_max_area = largestRectangleArea(heights);
            //cout << local_max_area << endl;
            max_area = max(max_area, local_max_area);
        }
        return max_area;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)  return 0;
        stack<int> my_stack;
        int max_area = 0;
        my_stack.push(0);
        int i = 1;
        while (i < n) {
            while (i < n) {
                int top_height = heights[my_stack.top()];
                if (heights[i] < top_height)  break;
                my_stack.push(i);
                i++;
            }
            int right = my_stack.top();
            while (i < n && !my_stack.empty()) {
                int top_height = heights[my_stack.top()];
                if (top_height <= heights[i])  break;
                my_stack.pop();
                int left;
                if (!my_stack.empty()) {
                    left = my_stack.top() + 1;
                } else {
                left = 0;
                }
                int area = top_height * (right - left + 1);
                max_area = max(max_area, area);
            }
            if (i < n) my_stack.push(i);
            i++;
        }
        int right = my_stack.top();
        while (!my_stack.empty()) {
            int top_height = heights[my_stack.top()];
            my_stack.pop();
            int left;
            if (!my_stack.empty()) {
                left = my_stack.top() + 1;
            } else {
                left = 0;
            }
            int area = top_height * (right - left + 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};