class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> num;
        while (true) {
            int tmp = 0;
            while (n != 0) {
                int r = n % 10;
                tmp += r * r;
                n = n / 10;
            }
            if (tmp == 1)  return true;
            if (num.count(tmp) > 0)  return false;
            num.insert(tmp);
            n = tmp;
        }
        return false;
    }
};