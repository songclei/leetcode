class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp;
        if (s.length() == 0)  return ret;
        _partition(s, 0, tmp, ret);
        return ret;
    }
    
    void _partition(string s, int p, vector<string> &tmp, vector<vector<string>> &ret) {
        if (p == s.length()) {
            ret.push_back(tmp);
            return;
        }
        for (int i = p; i < s.length(); ++i) {
            if (isPalindrome(s, p, i)) {
                tmp.push_back(s.substr(p, i-p+1));
                _partition(s, i+1, tmp, ret);
                tmp.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string s, int begin, int end) {
        int i = begin;
        int j = end;
        bool ret = true;
        while (i <= j) {
            if (s[i] != s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
};