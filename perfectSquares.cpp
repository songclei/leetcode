class Solution {
public:
    int numSquares(int n) {
        if (int(sqrt(n)) * int(sqrt(n)) == n) 
            return 1;
        vector<int> f(n);
        for (int i = 1; i <= n; ++i) {
            if (int(sqrt(i)) * int(sqrt(i)) == i)  f[i-1] = 1;
            else {
                int min_n = i;
                for (int j = 1; j <= sqrt(i); ++j) {
                    if (1 + f[i-j*j-1] < min_n)
                        min_n = 1 + f[i-j*j-1];
                }
                f[i-1] = min_n; 
            }
        }
        return f[n-1];
    }
};