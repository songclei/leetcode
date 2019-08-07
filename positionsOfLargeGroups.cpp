class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int n = S.length();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j < n && S[j] == S[i])  j++;
            if (j - i >= 3) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j-1);
                ans.push_back(tmp);
            } 
            i = j;
        }
        return ans;
    }
};