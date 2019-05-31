class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        long base = 5;
        while (base <= n) {
            ret += n / base;
            base *= 5;
        }
        return ret;
    }
};