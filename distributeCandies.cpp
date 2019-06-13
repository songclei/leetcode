class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        unordered_set<int> candy_set;
        for (int i = 0; i < n; ++i)
            candy_set.insert(candies[i]);
        int k = candy_set.size();
        if (k >= n / 2)  return n / 2;
        else  return k;
    }
};