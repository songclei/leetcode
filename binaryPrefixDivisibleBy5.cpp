class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> ret(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur * 2 + A[i]) % 10;
            if (cur % 5 == 0) {
                ret[i] = true;
            } else {
                ret[i] = false;
            }
        }
        return ret;
    }
};