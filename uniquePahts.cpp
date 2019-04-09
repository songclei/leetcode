class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)  return 0;
        if (m == 1 || n == 1)  return 1;
        vector<vector<int>> f;
        f.resize(m+1);
        for (int i = 0; i < m+1; ++i)
            f[i].resize(n+1);
        for (int i = 1; i <= m; ++i)
            f[i][1] = 1;
        for (int i = 1; i <= n; ++i)
            f[1][i] = 1;
        for (int i = 2; i <= m; ++i)
            for (int j = 2; j <= n; ++j) {
                f[i][j] = f[i][j-1] + f[i-1][j];
            }
        return f[m][n];
    }
};