class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] == i)
                    cnt++;
                if (cnt == 2)  return i;
            }
        }
        return 0;
    }
};