class Solution {
    string itoa(int i) {
        string s;
        while (i != 0) {
            s += '0' + i % 10;
            i /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        if (n <= 0)  return ret;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0)  ret.push_back("FizzBuzz");
            else if (i % 3 == 0)  ret.push_back("Fizz");
            else if (i % 5 == 0)  ret.push_back("Buzz");
            else  ret.push_back(itoa(i));
        }
        return ret;
    }
};