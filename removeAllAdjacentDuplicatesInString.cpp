class Solution {
public:
    string removeDuplicates(string S) {
        bool hasDup = true;
        while (hasDup) {
            hasDup = false;
            int l = S.length();
            for (int i = 0; i < l - 1; ++i) {
                if (S[i] == S[i+1]) {
                    S.erase(i, 2);
                    hasDup = true;
                    l -= 2;
                }
            }
        }
        return S;
    }
};