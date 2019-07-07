class Solution {
    int solution;
    vector<bool> line;
    vector<bool> left;
    vector<bool> right;
public:
    int totalNQueens(int n) {
        if (n == 0)  return 0;
        solution = 0;
        vector<bool>().swap(line);
        vector<bool>().swap(left);
        vector<bool>().swap(right);
        line.resize(n);
        left.resize(2*n-1);
        right.resize(2*n-1);
        putQueue(0, n);
        return solution;
    }
    
    void putQueue(int i, int n) {
        if (i == n)  {
            solution++;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (line[j] == false && right[j+i] == false && left[n-1-i+j] == false) {
                line[j] = true;
                right[j+i] = true;
                left[n-1-i+j] = true;
                putQueue(i+1, n);
                line[j] = false;
                right[j+i] = false;
                left[n-1-i+j] = false;
            } 
        }
    }
};