class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> line = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        vector<string> ret;
        for (int i = 0; i < words.size(); ++i) {
            int curLine = 0;
            if (words[i][0] >= 'a' && words[i][0] <= 'z')
                curLine = line[words[i][0]-'a'];
            else 
                curLine = line[words[i][0]-'A'];
            int j = 1;
            for (; j < words[i].length(); ++j) {
                if (words[i][j] >= 'a' && words[i][j] <= 'z') {
                    if (line[words[i][j]-'a'] != curLine)  break;
                } else {
                    if (line[words[i][j]-'A'] != curLine)  break;
                }
            }
            if (j == words[i].length())  ret.push_back(words[i]);
        }
        return ret;
    }
};