class Solution {
public:
    string minWindow(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        if (ls == 0)  return "";
        // my_map中存储t中的字母在子串中出现的次数
        unordered_map<char, int> my_map;
        unordered_map<char, int> char_cnt;
        int min_begin = -1;
        int min_length = ls + 1;
        // i表示子串开头，j表示子串结束
        int i = -1;
        int j = -1;
        int cnt = 0;
        int tot = 0;
        for (int k = 0; k < lt; ++k) {
            my_map.insert(make_pair(t[k], 0));
            if (char_cnt.count(t[k]) > 0) 
                char_cnt[t[k]]++;
            else  {
                tot++;
                char_cnt.insert(make_pair(t[k], 1));
            }
        }
        // 找到第一个在t中的字符
        for (i = 0; i < ls; ++i) {
            // 用哈希方式查看s[i]是否出现在t中
            if (my_map.count(s[i]) > 0) {
                if (++my_map[s[i]] == char_cnt[s[i]]) cnt++;
                break;
            }
        }
        // 找不到任何一个t中的字符
        if (i >= ls)  return "";
        if (lt == 1)  return t;
        j = i + 1;
        while (i < ls && j < ls) {
            // cnt == lt时，说明t中的每个字符在子串中都出现过了
            while (j < ls && cnt < tot) {
                if (my_map.count(s[j]) > 0) {
                    if (++my_map[s[j]] == char_cnt[s[j]]) cnt++;
                }
                j++;
            }
            //cout << "i=" << i << " j=" << j << endl;
            //cout << cnt << endl;
            // i向右找，将连续重复出现过的字符去掉
            while (i < ls && cnt == tot) {
                if (j - i < min_length) {
                    min_length = j - i;
                    min_begin = i;
                    //cout << s.substr(min_begin, min_length) << endl;
                }
                while (i < ls && cnt == tot) {
                    // 该字符在子串中不重复出现
                    if (my_map.count(s[i]) > 0 && --my_map[s[i]] < char_cnt[s[i]]) {
                        cnt--;
                    }
                    i++;
                    break;
                }
                // i向右找到第一个在t中出现的字符串
                while (i < ls) {
                    if (my_map.count(s[i]) > 0)  break;
                    i++;
                }
            }
        }
        if (min_begin == -1)  return "";
        else return s.substr(min_begin, min_length);
    }
};