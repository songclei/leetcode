class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set;
        for (int i = 0; i < banned.size(); ++i)  banned_set.insert(banned[i]);
        unordered_map<string, int> string_map;
        int left = 0;
        int right = 0;
        int l = paragraph.size();
        while (left < l) {
            left = right;
            while (left < l && !(paragraph[left] >= 'a' && paragraph[left] <= 'z') && !(paragraph[left] >= 'A' && paragraph[left] <= 'Z')) left++;
            right = left;
            while (right < l && ((paragraph[right] >= 'a' && paragraph[right] <='z') || paragraph[right] >= 'A' && paragraph[right] <='Z'))   {
                if (paragraph[right] >= 'A' && paragraph[right] <= 'Z')  {
                    paragraph[right] = paragraph[right] - 'A' + 'a';
                }
                right++;
            }
            if (left < l) {
                string word = paragraph.substr(left, right - left);
                if (banned_set.count(word) == 0) {
                    if (string_map.count(word) == 0)  string_map[word] = 1;
                    else string_map[word]++;
                }
            }
        }
        int maxFreq = 0;
        string returnWord;
        for (auto it = string_map.begin(); it != string_map.end(); ++it) {
            if (it->second > maxFreq) {
                maxFreq = it->second;
                returnWord = it->first;
            } else if (it->second == maxFreq && it->first > returnWord) {
                returnWord = it->first;
            } 
        }
        return returnWord;
    }
};