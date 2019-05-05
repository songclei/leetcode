class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0)  return 0;
        vector<int> f(amount+1);
        for (int i = 1; i <= amount; ++i)  f[i] = -1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (coins[j] == i) {
                    f[i] = 1;
                    break;
                }
                else if (coins[j] < i) {
                    if (f[i-coins[j]] != -1) {
                        if (f[i] == -1)  f[i] = f[i-coins[j]] + 1;
                        else  f[i] = min(f[i], f[i-coins[j]]+1);
                    }
                }
            }
        }
        return f[amount];
    }
};