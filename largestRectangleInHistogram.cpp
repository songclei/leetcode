class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)  return 0;
        if (n == 1)  return heights[0];
        int max_area = 0;
        // 储存：（坐标，高度）
        stack<pair<int,int>> my_stack;
        my_stack.push(make_pair(0, heights[0]));
        int i = 1;
        while (i < n) {
            cout << i << " ";
            while (i < n && heights[i] >= heights[i-1]) {
                my_stack.push(make_pair(i, heights[i]));
                i++;
            }
            if (i < n) {
                int right_index = my_stack.top().first;
                while (!my_stack.empty()) {
                    int j = my_stack.top().first;
                    int j_height = my_stack.top().second;
                    if (j_height <= heights[i])  break;
                    my_stack.pop();
                    int left_index;
                    if (!my_stack.empty()) 
                        left_index = my_stack.top().first + 1;
                    else 
                        left_index = 0;
                    int area = j_height * (right_index - left_index + 1);
                    if (area > max_area)  max_area = area;
                }
                my_stack.push(make_pair(i, heights[i]));
                i++;
            }
        }
        int right_index = my_stack.top().first;
        while (!my_stack.empty()) {
            int j = my_stack.top().first;
            int j_height = my_stack.top().second;
            my_stack.pop();
            int left_index;
            if (!my_stack.empty()) 
                    left_index = my_stack.top().first + 1;
                else 
                    left_index = 0;
            int area = j_height * (right_index - left_index + 1);
            if (area > max_area)  max_area = area;
        }
        return max_area;
    }
};