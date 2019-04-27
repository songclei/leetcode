class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;
        int n = people.size();
        if (n == 0)  return ret;
        sort(people.begin(), people.end(), my_compare);
        for (int i = 0; i < n; ++i) {
            ret.insert(ret.begin()+people[i][1], people[i]);
        }
        return ret;
    }
    
    static bool my_compare(const vector<int> p1, const vector<int> p2) {
        if (p1[0] == p2[0])  return p1[1] < p2[1];
        else  return p1[0] > p2[0];
    }
};