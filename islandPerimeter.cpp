class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)  return 0;
        int n = grid[0].size();
        int peri = 0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)  continue; 
                int surNum = 0;
                for (int k = 0; k < 4; ++k) {
                    if (i + dx[k] >= m || i + dx[k] < 0 || j + dy[k] >= n || j + dy[k] < 0) 
                        continue;
                    if (grid[i+dx[k]][j+dy[k]] == 1)  surNum++;
                }
                peri += 4 - surNum;
                // cout << surNum << endl;
            }
        }
        return peri;
    }
};