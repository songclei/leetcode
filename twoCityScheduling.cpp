class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)  return 0;
        vector<pair<int, int>> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = make_pair(abs(costs[i][0]-costs[i][1]), i);
        }
        sort(diff.begin(), diff.end(), my_compare);
        int A = 0;
        int B = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int index = diff[i].second;
            if (A == n / 2)  cnt += costs[index][1];
            else if (B == n / 2)  cnt += costs[index][0];
            else {
                if (costs[index][0] > costs[index][1]) {
                    cnt += costs[index][1];
                    B++;
                } else {
                    cnt += costs[index][0];
                    A++;
                }
                
            }
        }
        return cnt;
    }
    
    static bool my_compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
};