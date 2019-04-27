class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1);
        ret[0] = 0;
        if (num == 0)  return ret;
        ret[1] = 1;
        int cur = 2;
        while (cur <= num) {
            int total = cur;
            int t = 0;
            while (t < total && cur <= num) {
                ret[cur] = ret[cur-total] + 1;
                t++;
                cur++;
            }
        }
        return ret;
    }
};