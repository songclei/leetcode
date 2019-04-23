class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)  return 0;
        int n = matrix[0].size();
        vector<vector<int>> f(m);
        int max_square = 0;
        for (int i = 0; i < m; ++i)
            f[i].resize(n);
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == '1')  {
                f[i][0] = 1;
                max_square = 1;
            }
            else  f[i][0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == '1') {
                f[0][i] = 1;
                max_square = 1;
            }
            else  f[0][i] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0')  f[i][j] = 0;
                else {
                    f[i][j] = min(f[i-1][j], min(f[i-1][j-1], f[i][j-1])) + 1;
                    if (f[i][j] > max_square)
                        max_square = f[i][j];
                }
            }
        }
        return max_square * max_square;
    }
};