class NumArray {
    vector<int> sumFromBegin;
public:
    NumArray(vector<int>& nums) {
        vector<int>().swap(sumFromBegin);
        int n = nums.size();
        if (n == 0)  return;
        sumFromBegin.resize(n);
        sumFromBegin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sumFromBegin[i] = sumFromBegin[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0)  return sumFromBegin[j];
        else  return sumFromBegin[j] - sumFromBegin[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */