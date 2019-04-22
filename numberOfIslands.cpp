class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)  return 0;
        int n = grid[0].size();
        int island = 0;
        vector<vector<bool>> visited(m);
        for (int i = 0; i < m; ++i)
            visited[i].resize(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    island++;
                }
            }
        }
        return island;
    }
    
    void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> my_queue;
        visited[x][y] = true;
        my_queue.push(make_pair(x, y));
        while (!my_queue.empty()) {
            int cx = my_queue.front().first;
            int cy = my_queue.front().second;
            my_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)  continue;
                if (visited[nx][ny] || grid[nx][ny] != '1')  continue;
                visited[nx][ny] = true;
                my_queue.push(make_pair(nx, ny));
            }
        }
    }
};