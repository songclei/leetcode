class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return false;
        if (n == 1)  return true;
        int i = 1;
        int max_reach = nums[0];
        while (i <= max_reach) {
            if (max_reach >= n-1)  return true;
            int reach = i + nums[i];
            if (reach > max_reach)  max_reach = reach;
            i++;
        }
        if (max_reach >= n-1)  return true;
        return false;
    }
};