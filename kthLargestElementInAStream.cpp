class KthLargest {
    vector<int> list;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        list = nums;
        sort(list.begin(), list.end(), greater<int>());
    }
    
    int add(int val) {
        int left = 0;  int right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] > val)  left = mid + 1;
            else  right = mid - 1;
        }
        list.insert(list.begin()+left, val);
        return list[kth-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */