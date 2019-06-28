class Solution {
public:
    bool isValid(string S) {
        int l = S.length();
        if (l % 3 != 0)  return false;
        while ((l = S.length()) >= 3) {
            //cout << S << endl;
            bool find = false;
            for (int i = 0; i <= l - 3; ++i) {
                if (S.substr(i, 3) == "abc") {
                    find = true;
                    S = S.substr(0, i) + S.substr(i+3, l-i-3);
                    break;
                }
            }
            if (!find)  return false;
        }
        if (l == 0)  return true;
        return false;
    }
};