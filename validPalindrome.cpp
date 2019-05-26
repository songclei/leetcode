class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0 || n == 1)  return true;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int i_index;
            int j_index;
            while (i < j && (i_index = characterIndex(s[i])) == -1) i++;
            while (i < j && (j_index = characterIndex(s[j])) == -1) j--;
            //cout << i << " " << j << endl;
            if (i < j && i_index != j_index)  return false;
            i++;
            j--;
        }
        return true;
    }
    
    int characterIndex(char c) {
        if (c >= 'A' && c <= 'Z')  return c - 'A';
        else if (c >= 'a' && c <= 'z')  return c - 'a';
        else if (c >= '0' && c <= '9')  return c;
        else return -1;
    }
};