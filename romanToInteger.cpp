class Solution {
    
public:
    int romanToInt(string s) {
        int n = s.length();
        if (n == 0)  return 0;
        int ret = 0;
        unordered_map<char, int> roman2int;
        roman2int.insert(make_pair('I', 1));
        roman2int.insert(make_pair('V', 5));
        roman2int.insert(make_pair('X', 10));
        roman2int.insert(make_pair('L', 50));
        roman2int.insert(make_pair('C', 100));
        roman2int.insert(make_pair('D', 500));
        roman2int.insert(make_pair('M', 1000));
        int cur_max = roman2int[s[n-1]];
        for (int i = n-1; i >= 0; --i) {
            if (roman2int[s[i]] == cur_max) {
                ret += roman2int[s[i]];
            } else if (roman2int[s[i]] > cur_max) {
                ret += roman2int[s[i]];
                cur_max = roman2int[s[i]];
            } else {
                ret -= roman2int[s[i]];
            }
        }
        return ret;
    }
};