pair<int, int> getHourAndMin(const string &t) {
    int i = 0;
    int n = t.size();
    while (i < n && t[i] != ':')  i++;
    pair<int, int> ans;
    ans.first = atoi(t.substr(0, i).c_str());
    ans.second = atoi(t.substr(i+1, n-i-1).c_str());
    return ans;
}

// t1 <= t2
int timeDiff(const pair<int, int>& t1, const pair<int, int>& t2) {
    return (t2.first - t1.first) * 60 + t2.second - t1.second;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n == 1)  return 0;
        vector<pair<int, int>> time(n);
        for (int i = 0; i < n; ++i) {
            time[i] = getHourAndMin(timePoints[i]);
        }
        sort(time.begin(), time.end(), my_compare);
        int min_diff = timeDiff(time[n-1], make_pair((time[0].first)+24, time[0].second));
        for (int i = 0; i < n - 1; ++i) {
            min_diff = min(min_diff, timeDiff(time[i], time[i+1]));
        }
        return min_diff;
    }
    
    static bool my_compare(const pair<int, int> &time1, const pair<int, int> &time2) {
        if (time1.first == time2.first)  return time1.second < time2.second;
        else  return time1.first < time2.first;
    }
};


