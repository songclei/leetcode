class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        if (n <= 2)  return false;
        int sum = 0;
        for (int i = 0; i < n; ++i)  sum += A[i];
        if (sum % 3 != 0)  return false;
        int tmp = 0;
        int indexI = 0;
        for (; indexI < n - 2; ++indexI) {
            tmp += A[indexI];
            if (sum / 3 == tmp)  break;
        }
        if (indexI == n - 2)  return false;
        int indexJ = indexI + 1;
        //cout << indexJ << endl;
        tmp = 0;
        for (; indexJ < n - 1; ++indexJ) {
            tmp += A[indexJ];
            if (sum / 3 == tmp)  return true;
        }
        return false;
    }
};