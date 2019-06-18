class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n == 0)  return 0;
        vector<int> diff(n-1);
        for (int i = 0; i < n - 1; ++i)
            diff[i] = A[i+1] - A[i];
        int i = 0;
        int j = 0;
        int ret = 0;
        while (i < n - 1) {
            while (j < n - 2 && diff[j+1] == diff[j])  j++;
            if (i != j) {
                int sequenceNum = j - i + 2;
                ret += (sequenceNum - 1) * (sequenceNum - 2) / 2;
                // cout << ret << endl;
            }
            i = j + 1;
            j = i;
        }
        return ret;
    }
};