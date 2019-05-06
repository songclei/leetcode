class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        if (n == 0)  return ret;
        vector<bool> appear(n);
        for (int i = 0; i < n; ++i)  appear[nums[i]-1] = true;
        for (int i = 0; i < n; ++i) {
            if (appear[i] == false)  ret.push_back(i+1);
        }
        return ret;
    }
};