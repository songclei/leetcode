class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1)  return 0;
        int max_profit = 0;
        vector<int> f(n);
        f[0] = 0;
        f[1] = prices[1] - prices[0];
        if (f[1] > max_profit)  max_profit = f[1];
        if (n == 2)  return max_profit;
        f[2] = prices[2] - min(prices[0], prices[1]);
        if (f[2] > max_profit)  max_profit = f[2];
        
        vector<vector<int>> min_p(n);
        for (int i = 0; i < n; ++i)  min_p[i].resize(n);
        for (int i = 0; i < n; ++i)  min_p[i][i] = prices[i];
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                min_p[i][j] = min(min_p[i][j-1], prices[j]);
            }
        }
        
        for (int i = 3; i < n; ++i) {
            // sell at day i, and no other sell at other days
            int min_prices = prices[0];
            f[i] = prices[i] - min_p[0][i-1];
            
            // sell at day i, and last sell day is day j
            for (int j = 1; j < i - 2; ++j) {
                // day j+1 cooldown, and can only buy from day j+2;
                if (f[j] + prices[i] - min_p[j+2][i-1] > f[i])  
                    f[i] = f[j] + prices[i] - min_p[j+2][i-1];
            }
        
            if (f[i] > max_profit)  max_profit = f[i];
        }
        //for (int i = 0; i < n; ++i)  cout << f[i] << endl;
        return max_profit;
    }
};