class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.length();
        vector<int> ans;
        int l = 0, r = n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') {
                ans.push_back(l++);
            } else {
                ans.push_back(r--);
            }
        }
        ans.push_back(l);
        return ans;
    }
};