class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> numOfMaxDegree;
        int max_degree = 0;
        unordered_map<int, pair<int, int>> firstAndLastMap;
        unordered_map<int, int> cntMap;
        for (int i = 0; i < n; ++i) {
            if (cntMap.count(nums[i]) == 0) {
                cntMap[nums[i]] = 1;
                firstAndLastMap[nums[i]] = make_pair(i, i);
            } else {
                cntMap[nums[i]]++;
                firstAndLastMap[nums[i]].second = i;
            }
            if (cntMap[nums[i]] == max_degree)  numOfMaxDegree.push_back(nums[i]);
            else if (cntMap[nums[i]] > max_degree) {
                max_degree = cntMap[nums[i]];
                vector<int>().swap(numOfMaxDegree);
                numOfMaxDegree.push_back(nums[i]);
            }
        }
        int minLen = n;
        for (int i = 0; i < numOfMaxDegree.size(); ++i)
            minLen = min(minLen, firstAndLastMap[numOfMaxDegree[i]].second - firstAndLastMap[numOfMaxDegree[i]].first + 1);
        return minLen;
    }
};