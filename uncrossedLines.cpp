class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int na = A.size();
        int nb = B.size();
        if (na == 0 || nb == 0)  return 0;
        vector<vector<int>> f(na+1);
        for (int i = 0; i <= na; ++i)  f[i].resize(nb+1);
        for (int i = 1; i <= na; ++i) {
            for (int j = 1; j <= nb; ++j) {
                if (A[i-1] == B[j-1])  f[i][j] = f[i-1][j-1] + 1;
                else  f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
        return f[na][nb];
    }
};