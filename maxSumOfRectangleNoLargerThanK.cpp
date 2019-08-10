class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int K = k;
        int m = matrix.size();
        if (m == 0)  return 0;
        int n = matrix[0].size();
        vector<vector<int>> sumFromOrigin(m, vector<int>(n));
        sumFromOrigin[0][0] = matrix[0][0];
        for (int i = 1; i < n; ++i)  sumFromOrigin[0][i] = sumFromOrigin[0][i-1] + matrix[0][i];
        for (int i = 1; i < m; ++i)  sumFromOrigin[i][0] = sumFromOrigin[i-1][0] + matrix[i][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                sumFromOrigin[i][j] = sumFromOrigin[i-1][j] + sumFromOrigin[i][j-1] - sumFromOrigin[i-1][j-1] + matrix[i][j];
            }
        }
        int maxSum = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = i; k < m; ++k) {
                    for (int l = j; l < n; ++l) {
                        int sum;
                        if (i == 0 && j == 0) {
                            sum = sumFromOrigin[k][l];
                        } else if (i == 0) {
                            sum = sumFromOrigin[k][l] - sumFromOrigin[k][j-1];
                        } else if (j == 0) {
                            sum = sumFromOrigin[k][l] - sumFromOrigin[i-1][l];
                        } else {
                            sum = sumFromOrigin[k][l] - sumFromOrigin[i-1][l] - sumFromOrigin[k][j-1] + sumFromOrigin[i-1][j-1];
                        }
                        if (sum == K)  return K;
                        else if (sum < K)  maxSum = max(maxSum, sum);
                    }
                }
            }
        }
        return maxSum;
    }
};