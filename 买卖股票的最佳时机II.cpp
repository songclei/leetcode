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
    	if (size == 0 || size == 1)
    		return 0;
    	int max_profit = 0;
    	int i = 0, j = 0;
    	while (i < size-1 && j < size-1) {
    		while (i < size - 1 && prices[i+1] <= prices[i])  i++;
    		j = i;
    		while (j < size-1 && prices[j+1] >= prices[j]) j++;
    		max_profit += prices[j] - prices[i];
    		i = j;
    	}
    	return max_profit;
    }
};