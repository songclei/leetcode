class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        while (x > 0 || y > 0) {
            int x_last = x & 1;
            int y_last = y & 1;
            ret += x_last != y_last;
            x = x >> 1;
            y = y >> 1;
        }
        return ret;
    }
};