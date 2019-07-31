class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> my_map;
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i <= n - 10; ++i) {
            string tmp = s.substr(i, 10);
            if (my_map.count(tmp) > 0) {
                if (my_map[tmp] == 1)  ans.push_back(tmp);
                my_map[tmp]++;
            } else {
                my_map[tmp] = 1;
            }
        }
        return ans;
    }
};