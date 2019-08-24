class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.length();
        int l = 0;
        int r = 0;
        int cnt = 0;
        string ans = "";
        while (l < n) {
            if (S[r] == '(')  cnt++;
            else {
                cnt--;
                if (cnt == 0) {
                    ans += S.substr(l+1, r-l-1);
                    l = r + 1;
                }
            }
            r++;
        }
        return ans;
    }
};