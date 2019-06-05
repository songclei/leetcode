

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0)  return ret;
        ret.resize(n);
        vector<int> tmp;
        for (int i = n - 1; i >= 0; --i) {
            ret[i] = binaryInsert(tmp, nums[i]);
        }
        return ret;
    }
    
    int binaryInsert(vector<int>& sortedNums, int num) {
        int left = 0;
        int right = sortedNums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sortedNums[mid] >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //cout << left;
        sortedNums.insert(sortedNums.begin()+left, num);
        return left;
    }
};