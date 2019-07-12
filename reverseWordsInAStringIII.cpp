class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0; int j = 0;
        while (i < n && j < n) {
            while (i < n && s[i] == ' ')  i++;
            j = i + 1;
            while (j < n && s[j] != ' ')  j++;
            reverseWord(s, i, j-1);
            i = j + 1;
        }
        return s;
    }
    
    void reverseWord(string &s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};