class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0)  return ret;
        ret.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i+1);
            ret[i][0] = 1;
            ret[i][i] = 1;
        }
        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < i; ++j)
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        return ret;
    }
};