class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.length();
        int left = 0;
        int right = 0;
        int addLeft = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == '(')  left++;
            else {
                right++;
                if (right > left) {
                    addLeft = max(addLeft, right - left);
                }
            }
        }
        left = right = 0;
        int addRight = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == ')')  right++;
            else {
                left++;
                if (left > right) {
                    addRight = max(addRight, left - right);
                }
            }
        }
        return addLeft + addRight;
    }
};