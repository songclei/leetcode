class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0)  return vector<vector<int>>();
        int n = A[0].size();
        vector<vector<int>> trans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                trans[i][j] = A[j][i];
            }
        }
        return trans;
    }
};