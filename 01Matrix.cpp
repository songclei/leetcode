class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> my_queue;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                    my_queue.push(make_pair(i, j));
                }
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!my_queue.empty()) {
            pair<int, int> p = my_queue.front();
            my_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || ans[nx][ny] != -1)  continue;
                ans[nx][ny] = ans[p.first][p.second] + 1;
                my_queue.push(make_pair(nx, ny));
            }
        }
        return ans;
    }
};