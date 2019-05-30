class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0)  return 0;
        return _longestSubstring(s, 0, n-1, k);
    }
    
    int _longestSubstring(string s, int begin, int end, int k) {
        if (begin > end)  return 0;
        vector<int> cnt(26);
        unordered_set<char> less_than_k;
        for (int i = begin; i <= end; ++i)  cnt[s[i]-'a']++;
        bool satisfy = true;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k)  {
                less_than_k.insert('a'+i);
                satisfy = false;
            }
        }
        if (satisfy == true)  return end - begin + 1;
        int max_len = 0;
        int i = begin;
        int j;
        while (i <= end && j <= end) {
            while (i <= end && less_than_k.count(s[i]) > 0) i++;
            if (i > end)  return max_len;
            j = i + 1;
            while (j <= end && less_than_k.count(s[j]) == 0) j++;
            //cout << i << " " << j << endl;
            max_len = max(max_len, _longestSubstring(s, i, j-1, k));
            i = j + 1;
        }
        return max_len;
    }
};