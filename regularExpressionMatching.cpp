class Solution {
public:
    bool isMatch(string s, string p) {
        //cout << "compare <" << s << "> with <" << p << ">" << endl;
        int ls = s.length();
        int lp = p.length();
        if (ls == 0 && lp == 0)  return true;
        if (ls > 0 && lp == 0)  return false;
        int i = 0, j = 0;
        while (j < lp) {
            if (j == lp - 1 || p[j+1] != '*') {
                if (i == ls)  return false;
                if (p[j] != '.' && p[j] != s[i])  return false;
                i++;
                j++;
            }
            else if (p[j+1] == '*') {
                bool flag = false;
                for (int k = i;k <= ls; ++k) {
                    flag = isMatch(s.substr(k, ls-k), p.substr(j+2, lp-j-2));
                    if (flag)  return true;
                    if (p[j] != '.' && s[k] != p[j])  break;
                }
                return false;
            }
        }
        if (i == ls)  return true;
        else return false;
    }
};


