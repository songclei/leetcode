class MedianFinder {
    vector<int> nums;
    int size;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
        size++;
    }
    
    double findMedian() {
        if (size % 2 == 1)  return nums[size/2];
        else  return (nums[size/2-1] + nums[size/2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */