class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0)  return 0;
        sort(intervals.begin(), intervals.end(), my_compare);
        int cnt = 0;
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < right)  cnt++;
            else {
                right = intervals[i][1];
            }
        }
        return cnt;
    }
    
    static bool my_compare(const vector<int>& v1, const vector<int>& v2) {
        if (v1[1] == v2[1])  return v1[0] > v2[0];
        else return v1[1] < v2[1];
    }
};