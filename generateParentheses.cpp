class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", n, n);
        return ret;
    }
    
    void generate(vector<string> &v, string s, int l, int r) {
        if (l > r)  return;
        if (l == 0) {
            for (int i = 0; i < r; ++i)  s += ')';
            v.push_back(s);
            return;
        }
        generate(v, s+'(', l-1, r);
        generate(v, s+')', l, r-1);
    }
};