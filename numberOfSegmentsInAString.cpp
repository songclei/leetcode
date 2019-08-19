class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')  i++;
            if (i < n)  cnt++;
            while (i < n && s[i] != ' ')  i++;
        }
        return cnt;
    }
};