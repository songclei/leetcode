class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.length() - 1;
        while (i < j) {
            while (i < j && !isLetter(S[i])) i++;
            while (i < j && !isLetter(S[j])) j--;
            swap(S[i], S[j]);
            i++;
            j--;
        }
        return S;
    }
    
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};