class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool negtive = false;
        if (num == 0)  return "0";
        if (num < 0) {
            negtive = true;
            num =  -num;
        }
        while (num != 0) {
            ans = (char)('0' + num % 7) + ans;
            num = num / 7;
        }
        if (negtive)  ans = "-" + ans;
        return ans;
    }
};