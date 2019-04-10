class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        if (l1 == 0)  return l2;
        if (l2 == 0)  return l1;
        int dis[l1+1][l2+1];
        for (int i = 0; i <= l1; ++i)  dis[i][0] = i;
        for (int i = 0; i <= l2; ++i)  dis[0][i] = i;
        for (int i = 1; i <= l1; ++i)
            for (int j = 1; j <= l2; ++j) {
                if (word1[i-1] == word2[j-1])  dis[i][j] = dis[i-1][j-1];
                else 
                    dis[i][j] = min(min(dis[i-1][j-1], dis[i][j-1]), dis[i-1][j]) + 1;
            }
        return dis[l1][l2];
    }
};