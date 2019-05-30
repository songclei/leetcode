class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0)  return ret;
        unordered_map<int, int> my_map;
        for (int i = 0; i < n1; ++i) {
            if (my_map.count(nums1[i]) == 0)  my_map[nums1[i]] = 1;
            else  my_map[nums1[i]]++;
        }
        for (int i = 0; i < n2; ++i) {
            if (my_map.count(nums2[i]) > 0 && my_map[nums2[i]] > 0) {
                ret.push_back(nums2[i]);
                my_map[nums2[i]]--;
            }
        }
        return ret;
    }
};