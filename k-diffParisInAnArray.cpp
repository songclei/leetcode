class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if (k < 0)  return 0;
        unordered_set<int> num_hash;
        unordered_set<int> dup_hash;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (num_hash.count(nums[i]) > 0)  dup_hash.insert(nums[i]);
            else num_hash.insert(nums[i]);
        }
        if (k == 0)  return dup_hash.size();
        for (auto it = num_hash.begin(); it != num_hash.end(); ++it) {
            if (num_hash.count((*it)+k) > 0)  cnt++;
        }
        return cnt;
    }
};