class Solution {
public:
    bool isAnagram(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        if (ls != lt)  return false;
        unordered_map<char, int> char_cnt;
        for (int i = 0; i < ls; ++i) {
            if (char_cnt.count(s[i]) == 0)
                char_cnt[s[i]] = 1;
            else 
                char_cnt[s[i]]++;
        }
        for (int i = 0; i < ls; ++i) {
            if (char_cnt.count(t[i]) == 0)  return false;
            char_cnt[t[i]]--;
            if (char_cnt[t[i]] < 0) return false;
        }
        return true;
    }
};