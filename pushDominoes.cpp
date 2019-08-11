class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0;
        while (i < n) {
            if (dominoes[i] == '.')  i++;
            else if (dominoes[i] == 'L') {
                int j = i - 1;
                while (j >= 0 && dominoes[j] == '.') {
                    dominoes[j] = 'L';
                    j--;
                }
                i++;
            } else {
                int j = i + 1;
                while (j < n && dominoes[j] == '.')  j++;
                if (j < n && dominoes[j] == 'L') {
                    int ii = i + 1;
                    int jj = j - 1;
                    while (ii < jj) {
                        dominoes[ii] = 'R';
                        dominoes[jj] = 'L';
                        ii++;
                        jj--;
                    }
                    i = j + 1;
                } else {
                    for (int k = i + 1; k < j; ++k)  dominoes[k] = 'R';
                    i = j;
                }
            }
        }
        return dominoes;
    }
};