class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> f(amount+1);
        for (int i = 0; i <= amount; ++i) {
            f[i].resize(n+1);
        }
        for (int i = 0; i <= n; ++i)  f[0][i] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= n; ++j) {
                int t = i;
                while (t >= 0) {
                    f[i][j] += f[t][j-1];
                    t -= coins[j-1];
                }
            }
        }
        
        return f[amount][n];
    }
};