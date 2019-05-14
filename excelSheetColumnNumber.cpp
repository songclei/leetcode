class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ret = 0;
        if (n == 0)  return 0;
        ret += s[0] - 'A' + 1;
        for (int i = 1; i < n; ++i) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }
        return ret;
    }
};