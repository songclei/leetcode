class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ret;
        if (n == 0 || target <= 0)  return ret;
        sort(candidates.begin(), candidates.end());
        ret = comb(candidates, 0, n-1, target);
        return ret;
    }
    
    vector<vector<int>> comb(vector<int>& candidates, int l, int r, int target) {
        vector<vector<int>> ret;
        if (l > r || target < candidates[l])  return ret;
        for (int i = l; i <= r; ++i) {
            int remain = target - candidates[i];
            if (remain == 0) {
                vector<int> t = {candidates[i]};
                ret.push_back(t);
                break;
            }
            vector<vector<int>> v = comb(candidates, i, r, remain);
            for (int j = 0; j < v.size(); ++j) {
                vector<int> tmp = v[j];
                tmp.push_back(candidates[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};