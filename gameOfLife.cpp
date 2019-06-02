class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0)  return;
        int n = board[0].size();
        vector<vector<int>> next(m);
        for (int i = 0; i < m; ++i) {
            next[i].resize(n);
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0) {
                    if (countLiveNeighbors(board, i, j) == 3)
                        next[i][j] = 1;
                    else  
                        next[i][j] = 0;
                } else {
                    int liveNeighbors = countLiveNeighbors(board, i, j);
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                        next[i][j] = 0;
                    else 
                        next[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = next[i][j];
            }
        }
    }
    
    int countLiveNeighbors(vector<vector<int>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            if (x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n && board[x+dx[i]][y+dy[i]] == 1)
                cnt++;
        }
        return cnt;
    }
};