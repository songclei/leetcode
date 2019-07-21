class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_cnt;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (char_cnt.count(s[i]) == 0)  char_cnt[s[i]] = 1;
            else  char_cnt[s[i]]++;
        }
        vector<pair<char, int>> char_vec;
        for (auto it = char_cnt.begin(); it != char_cnt.end(); ++it) {
            char_vec.push_back(make_pair(it->first, it->second));
        }
        sort(char_vec.begin(), char_vec.end(), my_compare);
        string ans = "";
        for (int i = 0; i < char_vec.size(); ++i) {
            ans += string(char_vec[i].second, char_vec[i].first);
        }
        return ans;
    }
    
    static bool my_compare(const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second > p2.second;
    }
};