class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = -1;
        int cnt = 0;
        while (i < n) {
            cnt++;
            i = j + 1;
            j = i;
            for (; i <= j; ++i) {
                j = max(j, arr[i]);
            }
        }
        return cnt;
    }
};