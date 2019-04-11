class Solution {
/*
 * 这道题不能用广搜
 */
public:
    bool exist(vector<vector<char>>& board, string word) {
        int l = word.length();
        if (l == 0)  return true;
        int m = board.size();
        if (m == 0)  return false;
        int n = board[0].size();
        vector<vector<bool>> visited(m);
        for (int i = 0; i < m; ++i)  visited[i].resize(n);
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (_exist(board, visited, word, i, j, 0) == true)
                        return true;
                    visited[i][j] = false;
                }
            }
        return false;
    }
    
    bool _exist(vector<vector<char>>& board, vector<vector<bool>> visited, string word, int x, int y, int len) {
        int l = word.length();
        int m = board.size();
        int n = board[0].size();
        if (len == l - 1)  return true;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)  continue;
            if (!visited[nx][ny] && board[nx][ny] == word[len+1]) {
                visited[nx][ny] = true;
                if (_exist(board, visited, word, nx, ny, len+1))  return true;
                visited[nx][ny] = false;
            }
        }
        return false;
        
        
    }
};