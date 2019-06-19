class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxLen = 0;
        int nA = A.size();
        int nB = B.size();
        if (nA == 0 || nB == 0)  return 0;
        vector<int> f(nB);
        for (int i = 0; i < nB; ++i) {
            if (A[0] == B[i])  f[i] = 1;
            maxLen = max(f[i], maxLen);
        }
        for (int i = 0; i < nB; ++i)
            cout << f[i] << " ";
        cout << endl;
        for (int i = 1; i < nA; ++i) {
            for (int j = nB - 1; j >= 0; --j) {
                if (B[j] == A[i]) {
                    if (j == 0)  f[j] = 1;
                    else  f[j] = f[j-1] + 1;
                } else {
                    f[j] = 0;
                }
                maxLen = max(f[j], maxLen);
            }
        }
        return maxLen;
    }
};