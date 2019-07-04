class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = shifts.size();
        for (int i = n - 2; i >= 0; --i) {
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        }
        for (int i = 0; i < n; ++i) {
            S[i] = 'a' + (S[i] - 'a' + shifts[i]) % 26;
        }
        return S;
    }
};