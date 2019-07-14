class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        if (n == 0)  return 0;
        vector<int> zero_num;
        int one_cnt = 0;
        int zero_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) {
                zero_num.push_back(zero_cnt);
                zero_cnt = 0;
                one_cnt++;
            } else {
                zero_cnt++;
            }
        }
        zero_num.push_back(zero_cnt);
        int ans = 0;
        if (S == 0) {
            for (int i = 0; i < zero_num.size(); ++i) {
                ans += (zero_num[i] + 1) * zero_num[i] / 2;
            }
        } else {
            for (int i = 0; i < one_cnt + 1 - S; ++i) {
            ans += (1 + zero_num[i]) * (1 + zero_num[i+S]);
            }
        }
        return ans;
    }
};