class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0)  return digits;
        digits[n-1]++;
        int i = n - 1;
        while (i > 0 && digits[i] == 10) {
            digits[i] = 0;
            digits[i-1]++;
            i--;
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};