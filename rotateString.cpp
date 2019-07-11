class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length())  return false;
        if (A == B)  return true;
        int l = A.length();
        for (int i = 0; i < l; ++i) {
            if (A.substr(i, l-i) + A.substr(0, i) == B)  return true;
        }
        return false;
    }
};