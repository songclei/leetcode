class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length();
        vector<int> ans(n);
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                ans[i] = 0;
                pos = i;
            } else {
                if (pos == -1)  ans[i] = INT_MAX;
                else ans[i] = i - pos;
            }
        }
        pos = n;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C)  pos = i;
            else {
                if (pos != n) {
                    ans[i] = min(ans[i], pos - i);
                }
            }
        }
        return ans;
    }
};