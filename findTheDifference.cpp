class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> charCnt(26);
        int ls = s.length();
        int lt = t.length();
        for (int i = 0; i < ls; ++i)  charCnt[s[i]-'a']++;
        for (int i = 0; i < lt; ++i) {
            if (charCnt[t[i]-'a'] == 0)  return t[i];
            else charCnt[t[i]-'a']--;
        }
        return 'a';
    }
};