class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)  return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited;
        vector<vector<int>> cost;
        visited.resize(m);
        for (int i = 0; i < m; ++i)
            visited[i].resize(n);
        cost.resize(m);
        for (int i = 0; i < m; ++i)
            cost[i].resize(n);
        queue<pair<int, int>> my_queue;
        my_queue.push(make_pair(0, 0));
        visited[0][0] = true;
        cost[0][0] = grid[0][0];
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        while (!my_queue.empty()) {
            int x = my_queue.front().first;
            int y = my_queue.front().second;
            my_queue.pop();
            for (int i = 0; i < 2; ++i) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= m || newy < 0 || newy >= n)  continue;
                int newc = cost[x][y] + grid[newx][newy];
                if (!visited[newx][newy] || (visited[newx][newy] && cost[newx][newy] > newc)) {
                    visited[newx][newy] = true;
                    cost[newx][newy] = newc;
                    my_queue.push(make_pair(newx, newy));
                }
            }
        }
        return cost[m-1][n-1];
    }
};