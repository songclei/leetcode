class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int minNum = A[n-1];
        vector<int> loc(10001, -1);
        loc[A[n-1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] <= minNum) {
                minNum = A[i];
                loc[A[i]] = i;
            } else {
                for (int j = A[i] - 1; j >= 0; --j) {
                    if (loc[j] != -1) {
                        swap(A[i], A[loc[j]]);
                        break;
                    }
                }
                break;
            }
        }
        return A;
    }
};