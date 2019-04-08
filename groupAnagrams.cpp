class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int n = strs.size(); 
        if (n == 0)  return ret;
        map<string, vector<string>> my_map;
        for (int i = 0; i < n; ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            // 字典中当前不存在同类
            if (my_map.count(s) == 0) {
                vector<string> tmp = {strs[i]};
                my_map.insert(make_pair(s, tmp));
            } 
            // 存在同类，直接插入
            else {
                my_map[s].push_back(strs[i]);
            }
        }
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            ret.push_back(it->second);
        }
        return ret;
    }
};