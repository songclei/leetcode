class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            int n = s.length();
            string ss;
            for (int j = 0; j < n; ++j) {
                char c = s[j];
                int cnt = 1;
                j++;
                while (j < n && s[j] == c) {
                    cnt++;
                    j++;
                }
                ss += '0' + cnt;
                ss += c;
                j--;
            }
            s = ss;
        }
        return s;
    }
};