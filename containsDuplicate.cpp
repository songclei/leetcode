class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> my_set;
        int n = nums.size();
        if (nums.size() == 0)  return false;
        for (int i = 0; i < n; ++i) {
            if (my_set.count(nums[i]) > 0)  return true;
            my_set.insert(nums[i]);
        }
        return false;
    }
};