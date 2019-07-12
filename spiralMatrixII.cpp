class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) ans[i].resize(n);
        int t = 1;
        int d = 0;
        int x = 0;
        int y = 0;
        int cnt = n - 1;
        while (t <= n * n) {
            if (d == 0) {
                if (cnt == 0)  {
                    ans[x][y] = t++;
                    break;
                }
                for (int i = 0; i < cnt; ++i)
                    ans[x][y++] = t++; 
                d = 1;
            } else if (d == 1) {
                for (int i = 0; i < cnt; ++i) 
                    ans[x++][y] = t++;
                d = 2;
            } else if (d == 2) {
                for (int i = 0; i < cnt; ++i)
                    ans[x][y--] = t++;
                d = 3;
            } else if (d == 3) {
                for (int i = 0; i < cnt; ++i)
                    ans[x--][y] = t++;
                cnt -= 2;
                x += 1;
                y += 1;
                d = 0;
            }
        }
        return ans;
    }
};