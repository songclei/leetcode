/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> ret;
        if (n == 0) return ret;
        sort(intervals.begin(), intervals.end(), my_compare);
        int i = 0;
        while (i < n) {
            int left = intervals[i].start;
            int right = intervals[i].end;
            while (i < n && intervals[i].start <= right) {
                right = max(right, intervals[i].end);
                i++;
            }
            Interval tmp{left, right};
            ret.push_back(tmp);
        }
        return ret;
    }
    
    static bool my_compare(const Interval& i1, const Interval& i2) {
        if (i1.start == i2.start)  return i1.end < i2.end;
        else  return i1.start < i2.start;
    }
};