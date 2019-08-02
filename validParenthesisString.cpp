class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if (n == 0)  return true;
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*')  left++;
            else right++;
            if (right > left)  return false;
        }
        left = 0;
        right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*')  right++;
            else left++;
            if (left > right)  return false;
        }
        return true;
    }
};