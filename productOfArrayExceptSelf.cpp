class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        if (n == 0)  return ret;
        ret.resize(n);
        vector<int> product_from_first(n);
        product_from_first[0] = nums[0];
        vector<int> product_from_last(n);
        product_from_last[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i)  {
            product_from_first[i] = product_from_first[i-1] * nums[i];
            product_from_last[n-1-i] = product_from_last[n-i] * nums[n-1-i];
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0)  ret[i] = product_from_last[i+1];
            else if (i == n-1)  ret[i] = product_from_first[n-2];
            else  ret[i] = product_from_first[i-1] * product_from_last[i+1];
        }
        return ret;
    }
};