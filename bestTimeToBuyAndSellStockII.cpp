class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1)  return 0;
        int profit = 0;
        int i = 0;
        int local_min, local_max;
        while (i < n) {
            // 找局部最小
            while (i < n - 1 && prices[i+1] <= prices[i])  i++;
            // 最后一天不需要买了
            if (i != n - 1)  local_min = prices[i];
            else  break;
            // 找局部最大
            while (i < n - 1 && prices[i+1] >= prices[i])  i++;
            local_max = prices[i];
            profit += local_max - local_min;
        }
        return profit;
    }
};