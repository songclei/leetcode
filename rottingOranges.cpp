struct rottedOrange {
public:
    int x;
    int y;
    int t;
    rottedOrange(int _x, int _y, int _t): x(_x), y(_y), t(_t) {}
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)  return 0;
        int m = grid[0].size();
        int freshCount = 0;
        queue<rottedOrange> rotQueue;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    rotQueue.push(rottedOrange(i, j, 0));
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int time = 0;
        while (!rotQueue.empty()) {
            rottedOrange o = rotQueue.front();
            rotQueue.pop();
            int x = o.x;
            int y = o.y;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rotQueue.push(rottedOrange(nx, ny, o.t+1));
                    freshCount--;
                    time = o.t + 1;
                }
            }
        }
        if (freshCount != 0)  return -1;
        else  return time;
    }
};