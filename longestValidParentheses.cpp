class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0)  return 0;
        vector<int> f(n);
        f[0] = 0;
        int max_length = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(')  f[i] = 0;
            else {
                if (s[i-1] == '(') {
                    if (i == 1)  f[i] = 2;
                    else  f[i] = 2 + f[i-2];
                }
                else {
                    if (i - f[i-1] -1 < 0)  f[i] = 0;
                    else if (s[i-f[i-1]-1] == ')')  f[i] = 0;
                    else if (i - f[i-1] - 2 < 0)
                        f[i] = 2 + f[i-1];
                    else 
                        f[i] = 2 + f[i-1] + f[i-f[i-1]-2];
                }
            }
            if (f[i] > max_length)  max_length = f[i];
        }
        return max_length;
    }
};