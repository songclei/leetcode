class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        int max_len = 1;
        unordered_map<int, int> my_map;
        for (int i = 0; i < n; ++i)
            my_map.insert(make_pair(nums[i], i));
        vector<bool> visit(n);
        for (int i = 0; i < n; ++i) {
            if (visit[i])  continue;
            int len = 1;
            for (int j = nums[i]+1;;j++) {
                if (my_map.count(j) > 0) {
                    len++;
                    visit[my_map[j]] = true;
                } 
                else
                    break;
            }
            for (int j = nums[i]-1;;j--) {
                if (my_map.count(j) > 0) {
                    len++;
                    visit[my_map[j]] = true;
                }
                else
                    break;
            }
            if (len > max_len)
                max_len = len;
        }
        return max_len;
    }
};