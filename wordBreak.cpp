class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        int n = wordDict.size();
        if (n == 0)  return false;
        // f[i][j]表示s[i]...s[j]是否满足题目要求. f[i][j] = -1 表示未知状态. f[i][j] = 0表示不能用wordDict里的单词进行拆分, f[i][j] = 1 表示可以
        vector<vector<int>> f(l);
        for (int i = 0; i < l; ++i) {
            f[i].resize(l);
            // f[i][j]初始状态应该均为-1
            for (int j = 0; j < l; ++j)
                f[i][j] = -1;
        }
        // 对每个单词在s中进行查找，看是否有子串与该单词相同
        for (int i = 0; i < n; ++i) {
            int len = wordDict[i].length();
            for (int j = 0; j <= l - len; ++j) {
                // 某个子串与这个单词匹配上了
                if (s.substr(j, len) == wordDict[i]) { 
                    f[j][j+len-1] = 1;
                }
            }
        }
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                if (f[i][j] == -1)
                    _wordBreak(i, j, f);
            }
        }
        /*for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }*/
        return f[0][l-1];
    }
    
    void _wordBreak(int l, int r, vector<vector<int>> &f) {
        if (l == r)  {
            f[l][r] = 0;
            return;
        }
        for (int i = l; i < r; ++i) {
            if (f[l][i] == -1)  _wordBreak(l, i, f);
            if (f[i+1][r] == -1)  _wordBreak(i+1, r, f);
            if (f[l][i] == 1 && f[i+1][r] == 1) {
                f[l][r] = 1;
                return;
            }
        }
        f[l][r] = 0;
    }
};