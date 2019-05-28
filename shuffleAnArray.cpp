#define random(x) rand()%(x)

class Solution {
    vector<int> v;
    int size;
public:
    Solution(vector<int>& nums) {
        v = nums;
        size = v.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret;
        vector<int> tmp = v;
        for (int i = 0; i < size; ++i) {
            int t = random(size-i);
            //cout << t << endl;
            ret.push_back(tmp[t]);
            tmp[t] = tmp[size-i-1];
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */