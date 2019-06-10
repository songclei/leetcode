class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x == 0)  return true;
        vector<int> t;
        while (x != 0) {
            t.push_back(x%10);
            x = x / 10;
        }
        int i = 0;
        int j = t.size()-1;
        for (; i <= j; i++, j--) {
            if (t[i] != t[j])  return false;
        }
        return true;
    }
};