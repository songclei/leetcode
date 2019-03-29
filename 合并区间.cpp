#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalSort(const Interval& interval1, const Interval& interval2) {
	if (interval1.start == interval2.start)
		return interval1.end < interval2.end;
	else 
		return interval1.start < interval2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	int size = intervals.size();
    	sort(intervals.begin(), intervals.end(), intervalSort);
        vector<Interval> ret;
        if (size == 0)  return ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < size; ++i) {
        	if (intervals[i].start <= ret[ret.size()-1].end) {
        		ret[ret.size()-1].end = max(ret[ret.size()-1].end, intervals[i].end);
        	}
        	else
        		ret.push_back(intervals[i]);
        }
        return ret;
    }

};