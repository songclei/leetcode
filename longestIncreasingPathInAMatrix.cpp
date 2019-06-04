class Solution {
public:
    int longestIncreasingPath(const vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)  return 0;
        int n = matrix[0].size();
        vector<vector<int>> increasingPath(m);
        for(int i = 0; i < m; ++i)  increasingPath[i].resize(n);
        int longestPath = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (increasingPath[i][j] == 0) {
                    _longestIncreasingPath(matrix, increasingPath, i, j);
                }
                if (increasingPath[i][j] > longestPath) {
                    longestPath = increasingPath[i][j];
                }
            }
        }
        return longestPath;
    }
    
    void _longestIncreasingPath(const vector<vector<int>>& matrix, vector<vector<int>>& increasingPath, int x, int y) {
        //cout << x << " " << y << endl;
        if (increasingPath[x][y] != 0)  return;
        increasingPath[x][y] = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        int dx[8] = {-1, 0, 0, 1};
        int dy[8] = {0, -1, 1, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < matrix[x][y]) {
                if (increasingPath[nx][ny] == 0)  _longestIncreasingPath(matrix, increasingPath, nx, ny);
                if (increasingPath[nx][ny] + 1 > increasingPath[x][y])  
                    increasingPath[x][y] = increasingPath[nx][ny] + 1;
            }
        }
    }
};