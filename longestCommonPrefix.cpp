class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)  return "";
        string ret = strs[0];
        for (int i = 1; i < n; ++i) {
            string tmp = "";
            for (int j = 0; j < strs[i].size() && j < ret.size(); ++j) {
                if (strs[i][j] == ret[j])  tmp += ret[j];
                else break;
            }
            ret = tmp;
            if (ret == "")  return ret;
        }
        return ret;
    }
};