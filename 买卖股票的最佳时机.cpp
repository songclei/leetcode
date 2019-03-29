#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)  return 0;
        vector<int> maxPrice(size);
        maxPrice[size-1] = 0;
        int max_profit = 0;
        for (int i = size-2; i >= 0; --i) {
        	maxPrice[i] = maxPrice[i+1] > prices[i+1] ? maxPrice[i+1] : prices[i+1];
        	int profit = maxPrice[i] - prices[i];
        	max_profit = profit > max_profit ? profit : max_profit;
        }
        if (max_profit < 0)  max_profit = 0;
        return max_profit;
    }
};