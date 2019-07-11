class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), my_sort);
        for (int i = 0; i < d.size(); ++i) {
            int k = 0;
            int j;
            for (j = 0; j < d[i].size(); ++j) {
                while (k < s.length() && s[k] != d[i][j])  k++;
                if (k >= s.length())  break;
                k++;
            }
            if (j == d[i].length()) return d[i];
        }
        return "";
    }
    
    static bool my_sort(const string s1, const string s2) {
        if (s1.length() > s2.length())  return true;
        else if (s1.length() < s2.length())  return false;
        else  return s1 < s2;
    }
};