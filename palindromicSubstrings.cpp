class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n == 0)  return 0;
        vector<bool> odd(n, true);
        vector<bool> even(n, true);
        int total = 0;
        for (int len = 1; len <= n; len += 2) {
            for (int i = len / 2; i < n - len / 2; ++i) {
                if (odd[i] == true && s[i-len/2] == s[i+len/2]) {
                    total++;
                } else {
                    odd[i] = false;
                }
            }
        }
        for (int len = 2; len <= n; len += 2) {
            for (int i = len / 2 - 1; i < n - len / 2; ++i) {
                if (even[i] == true && s[i-len/2+1] == s[i+len/2]) {
                    total++;
                } else {
                    even[i] = false;
                }
            }
        }
        return total;
    }
};