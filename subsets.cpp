class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> t;
        _subsets(nums, 0, ret, t);
        return ret;
    }
    
    void _subsets(vector<int>& nums, int n, vector<vector<int>>& ret, vector<int>& t) {
        //cout << n << endl;
        int size = nums.size();
        if (size == n)  {
            ret.push_back(t);  
            return;
        }
        _subsets(nums, n+1, ret, t);
        t.push_back(nums[n]);
        _subsets(nums, n+1, ret, t);
        t.pop_back();
    }
};