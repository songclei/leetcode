class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        bool allZero = false;
        while (!allZero) {
            allZero = true;
            int oneCnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != 0) {
                    allZero = false;
                    if ((nums[i] & 1) == 1)  oneCnt++;
                    nums[i] = nums[i] >> 1;
                }
            }
            cnt += (n - oneCnt) * oneCnt;
        }
        return cnt;
    }
};

