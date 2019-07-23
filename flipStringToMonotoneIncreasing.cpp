class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int cnt1 = 0;
        int n = S.length();
        if (n == 0)  return 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == '1')  cnt1++;
        }
        int n_before = 0;
        int min_flip = cnt1;
        for (int i = 0; i < n; ++i) {
            if (S[i] == '1') {
                int n_after = cnt1 - n_before - 1;
                int flip = n_before + n - i - 1 - n_after;
                min_flip = min(min_flip, flip);
                n_before++;
            }
        }
        return min_flip;
    }
};