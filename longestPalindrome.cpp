class Solution {
public:
    int longestPalindrome(string s) {
        int l = s.length();
        if (l == 0)  return 0;
        int cnt = 0;
        vector<int> lower_cnt(26);
        vector<int> upper_cnt(26);
        for (int i = 0; i < l; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z')  lower_cnt[s[i]-'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z')  upper_cnt[s[i]-'A']++;
        }
        bool has_odd = false;
        for (int i = 0; i < 26; ++i) {
            if (lower_cnt[i] % 2 == 0)  cnt += lower_cnt[i];
            else {
                cnt += lower_cnt[i] - 1;
                has_odd = true;
            } 
            if (upper_cnt[i] % 2 == 0)  cnt += upper_cnt[i];
            else {
                cnt += upper_cnt[i] - 1;
                has_odd = true;
            }
        }
        if (has_odd)  cnt++;
        return cnt;
    }
};