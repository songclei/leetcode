class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> my_unset;
        int ret = 0;
        for (int i = 0; i < J.length(); ++i) {
            my_unset.insert(J[i]);
        }
        for (int i = 0; i < S.length(); ++i) {
            if (my_unset.count(S[i]) > 0)
                ret++;
        }
        return ret;
    }
};