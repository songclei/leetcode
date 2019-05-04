class Solution {
    int max_len;
    
     bool _validParentheses(string s)
    {
        int count = 0;
        for (int i = 0; i<s.length(); i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')'){
                if (count == 0)
                    return false;
                count--;
            }
        }
        return count == 0;
    }
    
    
    void _removeInvalidParentheses(string &s, int t, string &cur_s, vector<string>& ret, unordered_set<string> &my_set) {
        int n = s.length();
        if (n - t + cur_s.length() < max_len)  return;
        // 所有字符都考虑了，此时判断cur_s是否有效
        if (t == n) {
            if (_validParentheses(cur_s) && my_set.count(cur_s) == 0) {
                int l = cur_s.length();
                // 和当前最长的相等，说明是一个可能解，放入ret数组中
                if (l == max_len) {
                    ret.push_back(cur_s);
                    my_set.insert(cur_s);
                }
                // 大于当前最长，更新最长长度，并清空原先的ret数组
                if (l > max_len) {
                    max_len = l;
                    ret.clear();
                    ret.push_back(cur_s);
                    my_set.clear();
                    my_set.insert(cur_s);
                }
            }
        } else {
            // 为非括号的其他字符，直接判断下一个字符
            if (s[t] != '(' && s[t] != ')') {
                cur_s += s[t];
                _removeInvalidParentheses(s, t+1, cur_s, ret, my_set);
                cur_s.pop_back();
            }
            else {
                // 当前字符放入结果中
                cur_s += s[t];
                _removeInvalidParentheses(s, t+1, cur_s, ret, my_set);
                cur_s.pop_back();
                // 当前字符不放入结果中
                _removeInvalidParentheses(s, t+1, cur_s, ret, my_set);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> my_set;
        vector<string> ret;
        int n = s.length();
        if (n == 0)  {
            ret.push_back("");
            return ret;
        }
        max_len = 0;
        string tmp = "";
        _removeInvalidParentheses(s, 0, tmp, ret, my_set);
        return ret;
    }
    
    
};