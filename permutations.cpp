class Solution {
    vector<bool> visited;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited.resize(n);
        for (int i = 0; i < n; ++i)  visited[i] = false;
        return _permute(nums, n);
    }
    
    vector<vector<int>> _permute(vector<int>& nums, int n) {
        vector<vector<int>> ret;
        if (n == 0)  return ret;
        if (n == 1) {
            for (int k = 0; k < nums.size(); ++k) {
                if (!visited[k]) {
                    vector<int> v = {nums[k]};
                    ret.push_back(v);
                    return ret;
                }
            }
        }
        int i = 0;
        int cnt = 0;
        while (cnt < n) {
            if (!visited[i]) {
                visited[i] = true;
                vector<vector<int>> v = _permute(nums, n-1);
                for (int j = 0; j < v.size(); ++j) {
                    vector<int> tmp = v[j];
                    tmp.insert(tmp.begin(), nums[i]);
                    ret.push_back(tmp);
                }
                visited[i] = false;
                cnt++;
            }
            i++;
        }
        return ret;
    }
};