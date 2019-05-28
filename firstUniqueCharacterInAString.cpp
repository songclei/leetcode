class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> first_appear(26);
        int n = s.length();
        for (int i = 0; i < 26; ++i) {
            first_appear[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            if (first_appear[s[i]-'a'] == -1)
                first_appear[s[i]-'a'] = i;
            else first_appear[s[i]-'a'] = -2;
        }
        int ret = -1;
        for (int i = 0; i < 26; ++i) {
            if (first_appear[i] >= 0) {
                if (ret == -1)  ret = first_appear[i];
                else if (first_appear[i] < ret)  ret = first_appear[i];
            }
        }
        return ret;
    }
};