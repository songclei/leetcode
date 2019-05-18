class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> visited(9);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')  continue;
                if (visited[board[i][j]-'1'])  return false;
                visited[board[i][j]-'1'] = true;
            }
        }
        for (int j = 0; j < 9; ++j) {
            vector<bool> visited(9);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.')  continue;
                if (visited[board[i][j]-'1'])  return false;
                visited[board[i][j]-'1'] = true;
            }
        }
        vector<int> left_x = {0, 0, 0, 3, 3, 3, 6, 6, 6};
        vector<int> left_y = {0, 3, 6, 0, 3, 6, 0, 3, 6};
        vector<int> d_x = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        vector<int> d_y = {0, 1, 2, 0, 1, 2, 0, 1, 2};
        for (int i = 0; i < 9; ++i) {
            vector<bool> visited(9);
            for (int j = 0; j < 9; ++j) {
                if (board[left_x[i]+d_x[j]][left_y[i]+d_y[j]] == '.')  continue;
                int num = board[left_x[i]+d_x[j]][left_y[i]+d_y[j]] - '1';
                if (visited[num])  return false;
                visited[num] = true;
            }
        }
        return true;
    }
};