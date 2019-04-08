class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        _rotate(matrix, 0);
    }
    
    void _rotate(vector<vector<int>>& matrix, int left) {
        int n = matrix.size();
        if (n == 0 || n == 1)  return;
        int right = n - 1 - left;
        if (left >= right)  return;
        for (int i = left; i < right; ++i) {
            int tmp = matrix[left][i];
            matrix[left][i] = matrix[right-i+left][left];
            matrix[right-i+left][left] = matrix[right][right-i+left];
            matrix[right][right-i+left] = matrix[i][right];
            matrix[i][right] = tmp;
        }
        _rotate(matrix, left+1);
    }
};