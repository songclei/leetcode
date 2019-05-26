class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)  return;
        int n = board[0].size();
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O')  visit(board, 0, j);
            if (board[m-1][j] == 'O')  visit(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')  visit(board, i, 0);
            if (board[i][n-1] == 'O')  visit(board, i, n-1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'B')  board[i][j] = 'O';
                else if (board[i][j] = 'O')  board[i][j] = 'X';
            }
        }
        
    }
    
    void visit(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> my_queue;
        my_queue.push(make_pair(x, y));
        board[x][y] = 'B';
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!my_queue.empty()) {
            int cx = my_queue.front().first;
            int cy = my_queue.front().second;
            my_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                    board[nx][ny] = 'B';
                    my_queue.push(make_pair(nx, ny));
                }
            }
        }
    } 
};