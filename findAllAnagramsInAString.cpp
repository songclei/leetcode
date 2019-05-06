class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        int i = 0;
        int j = 0;
        int l = 0;
        vector<int> ret;
        unordered_map<char, int> my_map;
        for (int k = 0; k < lp; ++k) {
            if (my_map.count(p[k]) == 0)
                my_map[p[k]] = 1;
            else 
                my_map[p[k]]++;
        }
        unordered_map<char, int> count_map(my_map);
        while (i <= ls - lp) {
            while (l < lp) {
                // 字符在p中未出现
                if (count_map.count(s[j]) == 0) {
                    // cout << s[j] << " dose not appear in lp" << endl;  
                    i = j + 1;
                    j = i;
                    l = 0;
                    count_map = my_map;
                    break;
                } else {
                    // 字符出现次数已经足够，说明当前子串中已经出现过s[j]了。找到第一个与s[j]相同的字符
                    if (count_map[s[j]] == 0) {
                        // cout << "find first " << s[j] << endl; 
                        while (i < j && s[i] != s[j]) {
                            count_map[s[i]]++;
                            l--;
                            i++;
                        }
                        i++;
                    } 
                    else {
                        // cout << "find " << s[j] << "!" << endl;
                        count_map[s[j]]--;
                        l++;
                    }
                    j++;
                }
            }
            if (l == lp) {
                // cout << "l == lp：" << i << endl; 
                ret.push_back(i);
                count_map[s[i]]++;
                i++;
                l--;
            }
        }
        return ret;
    }
};