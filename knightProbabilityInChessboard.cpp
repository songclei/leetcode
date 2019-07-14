class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int cnt = 0;
        int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        vector<vector<double>> dp(N);
        for (int i = 0; i < N; ++i) {
            dp[i].resize(N);
            for(int j = 0; j < N; ++j) {
                dp[i][j] = 1;
            }
        }
        for (int k = 0; k < K; ++k) {
            vector<vector<double>> tmp(N);
            for (int i = 0; i < N; ++i) {
                tmp[i].resize(N);
                for (int j = 0; j < N; ++j) {
                    for (int t = 0; t < 8; ++t) {
                        int nx = i + dx[t];
                        int ny = j + dy[t];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N)  tmp[i][j] += dp[nx][ny];
                    }
                }
            }
            dp = tmp;
        }
        return pow(1.0 / 8, K) * dp[r][c];
    }
};