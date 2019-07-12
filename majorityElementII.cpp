class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1;
        int element2;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt1 == 0 && cnt2 == 0) {
                element1 = nums[i];
                cnt1 = 1;
            } else if (cnt1 == 0) {
                if (element2 == nums[i]) {
                    cnt2++;
                } else {
                    element1 = nums[i];
                    cnt1 = 1;
                }
            } else if (cnt2 == 0) {
                if (element1 == nums[i]) {
                    cnt1++;
                } else {
                    element2 = nums[i];
                    cnt2 = 1;
                }
            } else {
                if (element1 == nums[i]) {
                    cnt1++;
                } 
                else if (element2 == nums[i]) {
                    cnt2++;
                } else {
                    cnt1--;
                    cnt2--;
                }
            }
        }
        vector<int> ans;
        if (cnt1 != 0) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == element1)  cnt++;       
            }
            if (cnt > n / 3)  ans.push_back(element1);
        } 
        if (cnt2 != 0) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == element2)  cnt++;
            }
            if (cnt > n / 3)  ans.push_back(element2);
        }
        return ans;
    }
};