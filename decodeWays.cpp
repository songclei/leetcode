class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 1) {
            if (s[0] == '0') return 0;
            else return 1;
        }
        int f_2 = s[0] == '0' ? 0 : 1;
        int f_1;
        if (s[0] == '0')  f_1 = 0;
        else {
            if (s[1] == '0') {
                if (s[0] == '1' || s[0] == '2')  f_1 = 1;
                else f_1 = 0;
            } else if (s[1] >= '1' && s[1] <= '6') {
                if (s[0] == '1' || s[0] == '2')  f_1 = 2;
                else f_1 = 1;
            } else {
                if (s[0] == '1')  f_1 = 2;
                else f_1 = 1;
            }
        }
        for (int i = 2; i < n; ++i) {
            int f;
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')  f = f_2;
                else f = 0;
            } else if (s[i] >= '1' && s[i] <= '6') {
                if (s[i-1] == '1' || s[i-1] == '2')  f = f_1 + f_2;
                else  f = f_1;
            } else {
                if (s[i-1] == '1')  f = f_1 + f_2;
                else  f = f_1;
            }
            f_2 = f_1;
            f_1 = f;
        }
        return f_1;
    }
};