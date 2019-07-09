class Solution {
public:
    string addStrings(string num1, string num2) {
        string _short;
        string _long;
        if (num1.size() == 0)  return num2;
        if (num2.size() == 0)  return num1;
        if (num1.size() > num2.size()) {
            _short = num2;
            _long = num1;
        } else {
            _short = num1;
            _long = num2;
        }
        int lsize = _long.size();
        int ssize = _short.size();
        for (int i = 0; i < ssize; ++i) {
            _long[lsize-1-i] += _short[ssize-1-i] - '0';
        }
        for (int i = lsize - 1; i > 0; --i) {
            if (_long[i] > '9') {
                _long[i] -= 10;
                _long[i-1]++;
            }
        }
        if (_long[0] > '9') {
            _long[0] -= 10;
            _long = "1" + _long;
        }
        return _long;
    }
};