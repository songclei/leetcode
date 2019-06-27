class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int i = 0;
        int j = 0;
        int n = s.length();
        while (i < n && j < n) {
            while (i < n && s[i] == ' ')  i++;
            if (i == n)  break;
            j = i;
            while (j < n && s[j] != ' ')  j++;
            string tmp = s.substr(i, j-i);
            reverse(tmp.begin(), tmp.end());
            if (ret == "")  ret = tmp;
            else  ret += " " + tmp;
            i = j + 1;
        }
        //cout << ret << endl;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};