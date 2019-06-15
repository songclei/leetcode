class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret;
        long num1 = abs((long)numerator);
        long num2 = abs((long)denominator);
        long shang = num1 / num2;
        while (shang != 0) {
            int t = shang % 10;
            ret.insert(0, 1, '0'+shang % 10);
            shang = shang / 10;
        }
        if (ret.length() == 0)  ret += "0";
        long r = num1 % num2;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ret.insert(0, 1, '-');
        if (r == 0)  return ret; 
        ret += ".";
        unordered_map<int, int> my_map;
        int l = ret.length();
        while (r != 0) {
            if (my_map.count(r) == 0) {
                my_map.insert(make_pair(r, l));
            } else {
                ret.insert(my_map[r], 1, '(');
                ret += ')';
                break;
            }
            r *= 10;
            ret += '0' + r / num2;
            r = r % num2;
            l++;
        }
        return ret;
    }
};