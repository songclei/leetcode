class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> ans;
        if (m == 0)  return ans;
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        for (int i = 0; i < n; ++i)  pacific[0][i] = true;
        for (int i = 0; i < m; ++i)  pacific[i][0] = true;
        reachable(matrix, pacific);
        for (int i = 0; i < n; ++i)  atlantic[m-1][i] = true;
        for (int i = 0; i < m; ++i)  atlantic[i][n-1] = true;
        reachable(matrix, atlantic);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    vector<int> tmp = {i, j};
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
    
    void reachable(vector<vector<int>>& matrix, vector<vector<bool>>& visit) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> my_queue;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j] == true)  my_queue.push(make_pair(i, j));
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!my_queue.empty()) {
            int x = my_queue.front().first;
            int y = my_queue.front().second;
            my_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny] && matrix[nx][ny] >= matrix[x][y]) {
                    visit[nx][ny] = true;
                    my_queue.push(make_pair(nx, ny));
                }
            }
        }
    }
};