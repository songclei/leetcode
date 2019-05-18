class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        //if (ls == 0)  return true;
        //if (lp == 0)  return false;
        vector<vector<bool>> f(ls+1);
        for (int i = 0; i < ls+1; ++i)  f[i].resize(lp+1);
        f[0][0] = true;
        for (int i = 0; i < lp; ++i) {
            if (p[i] != '*')  break;
            f[0][i+1] = true;
        }
        for (int i = 1; i <= ls; ++i) {
            for (int j = 1; j <= lp; ++j) {
                if (p[j-1] == '?') {
                    f[i][j] = f[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    for (int k = 0; k <= i; ++k) {
                        if (f[k][j-1] == true) {
                            f[i][j] = true;
                            break;
                        }
                    }
                } 
                else if (p[j-1] == s[i-1]) {
                    f[i][j] = f[i-1][j-1];
                }
            }
        }
        return f[ls][lp];
    }
};