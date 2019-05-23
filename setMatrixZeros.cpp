class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)  return;
        int n = matrix[0].size();
        // matrix[i][0] 为 0表示第i行要设为0， matrix[0][j]为0表示第j列要设为0
        // 防止第一列/行被污染，所以需要设置zero_row, zero_column表示第一行和第一列
        bool zero_row = false;
        bool zero_column = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        zero_row = true;
                    if (j == 0)
                        zero_column = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        /*
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        */
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j)  matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i)  matrix[i][j] = 0;
            }
        }
        if (zero_row) {
            for (int j = 1; j < n; ++j) matrix[0][j] = 0;
        }
        if (zero_column) {
            for (int i = 1; i < m; ++i)  matrix[i][0] = 0;
        }
    }
};