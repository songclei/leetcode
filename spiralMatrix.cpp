class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0)  return ret;
        int n = matrix[0].size();
        int d = 0;
        int x = 0;
        int y = 0;
        while (m > 0 && n > 0) {
            switch (d) {
                case 0:
                    for (int i = 0;i < n; ++i)
                        ret.push_back(matrix[x][y++]);
                    d = 1;
                    x++;
                    y--;
                    m--;
                    break;
                case 1:
                    for (int i = 0; i < m; ++i)
                        ret.push_back(matrix[x++][y]);
                    d = 2;
                    y--;
                    x--;
                    n--;
                    break;
                case 2:
                    for (int i = 0; i < n; ++i) 
                        ret.push_back(matrix[x][y--]);
                    d = 3;
                    x--;
                    y++;
                    m--;
                    break;
                case 3:
                    for (int i = 0; i < m; ++i)
                        ret.push_back(matrix[x--][y]);
                    d = 0;
                    y++;
                    x++;
                    n--;
            }
        }
        return ret;
    }
};