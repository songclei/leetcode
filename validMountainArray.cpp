class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3)  return false;
        int i = 0;
        while (i < n - 1 && A[i+1] > A[i])  i++;
        if (i == 0 || i == n - 1)  return false;
        for (; i < n - 1; ++i) {
            if (A[i+1] >= A[i])  return false;
        }
        return true;
    }
};