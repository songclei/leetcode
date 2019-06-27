class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max = 0;
        int n = words.size();
        sort(words.begin(), words.end(), my_compare);
        for (int i = 0; i < n - 1; ++i) {
            unordered_set<char> my_set;
            int l1 = words[i].length();
            for (int k = 0; k < l1; ++k) {
                my_set.insert(words[i][k]);
            }
            for (int j = i + 1; j < n; ++j) {
                int l2 = words[j].length();
                if (l1 * l2 <= max)  break;
                int k = 0;
                for (; k < l2; ++k) {
                    if (my_set.count(words[j][k]) > 0)  break;
                }
                if (k != l2)  continue;
                if (l1 * l2 > max)  max = l1 * l2;
            }
        }
        return max;
    }
    
    static bool my_compare(const string& s1, const string& s2) {
        return s1.length() > s2.length();
    }
};