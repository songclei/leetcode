class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret(2);
        int k = nums.size();
        if (k == 1) {
            ret[0] = nums[0][0];
            ret[1] = nums[0][0];
            return ret;
        }
        vector<pair<int, int>> list;
        int total = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                list.push_back(make_pair(nums[i][j], i));
                total++;
            }
        }
        sort(list.begin(), list.end());
        int i = 0;
        int j = 1;
        vector<int> cnt(k);
        cnt[list[i].second] = 1;
        int in_range = 1;
        bool first = true;
        while (i < total && j < total) {
            //cout << i << " " << j << endl;
            while (j < total && in_range < k) {
                cnt[list[j].second]++;
                if (cnt[list[j].second] == 1)  in_range++;
                j++;
            }
            if (in_range == k) {
                if (first) {
                    ret[0] = list[i].first;
                    ret[1] = list[j-1].first;
                    first = false;
                }
                else if (ret[1] - ret[0] > list[j-1].first - list[i].first || (ret[1] - ret[0] == list[j-1].first - list[i].first && ret[0] > list[i].first)) {
                    ret[0] = list[i].first;
                    ret[1] = list[j-1].first;
                }
            }
            while (i < j && in_range == k) {
                cnt[list[i].second]--;
                if (cnt[list[i].second] == 0) {
                    in_range--;
                    i++;
                    break;
                }
                i++;
                if (ret[1] - ret[0] > list[j-1].first - list[i].first || (ret[1] - ret[0] == list[j-1].first - list[i].first && ret[0] > list[i].first)) {
                    ret[0] = list[i].first;
                    ret[1] = list[j-1].first;
                }
            }
        }
        return ret;
    }
};