class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        if (n == 0)  return 0;
        vector<int> f(n);
        f[0] = hours[0] > 8 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (hours[i] > 8)  f[i] = f[i-1] + 1;
            else  f[i] = f[i-1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j - i + 1 < ans)  continue;
                int td = 0;
                if (i == 0)  td = f[j];
                else  td = f[j] - f[i-1];
                if (td > j - i + 1 - td) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};