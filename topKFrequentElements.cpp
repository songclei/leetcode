struct elementCount {
    int val;
    int cnt;
    elementCount(int _val) {
        val = _val;
        cnt = 1;
    }
    
    const bool operator < (elementCount& e) {
        if (e.cnt == cnt)  return val < e.val;
        return cnt > e.cnt;
    }
    
    elementCount() {}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0)  return ret;
        unordered_map<int, elementCount*> my_map;
        vector<elementCount> my_vector(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (my_map.count(nums[i]) == 0) {
                my_vector[cnt].val = nums[i];
                my_vector[cnt].cnt = 1;
                my_map.insert(make_pair(nums[i], &my_vector[cnt]));
                cnt++;
            } else {
                (*(my_map[nums[i]])).cnt++;
            }
        }
        sort(my_vector.begin(), my_vector.begin()+cnt);
        for (int i = 0; i < k; ++i) {
            ret.push_back(my_vector[i].val);
        }
        return ret;
    }
};