class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)  return false;
        int cnt = 0;
        for (int i = 1; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                cnt += i;
                if (num / i != i && i != 1)  cnt += num / i;
            }
            if (cnt > num)  return false;
        }
        if (cnt == num)  return true;
        else return false;
    }
};