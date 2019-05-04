class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                int j = i + t;
                if (j >= n)  continue;
                for (int k = i; k <= j; ++k) {
                    //cout << i << " " << j << " " << k << endl;
                    int left = i == 0 ? 1 : nums[i-1];
                    int right = j == n - 1 ? 1 : nums[j+1];
                    int sum_mid = nums[k] * left * right;
                    int sum_left = k == i ? 0 : f[i][k-1];
                    int sum_right = k == j ? 0 : f[k+1][j];
                    f[i][j] = max(f[i][j], sum_mid+sum_left+sum_right);
                }
            }
        }
        return f[0][n-1];
    }
};