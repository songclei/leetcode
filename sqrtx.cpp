class Solution {
public:
    int mySqrt(int x) {
        long lx = x;
        long i = 0;
        while (i * i <= lx) {
            i++;
        }
        return (int)(i-1);
    }
};