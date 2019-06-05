class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2)  return 0;
        vector<bool> isPrime(n, true);
        isPrime[1] = false;
        isPrime[2] = true;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i] == false)  continue;
            int t = i * i;
            while (t < n) {
                isPrime[t] = false;
                t += i;
            }
        }
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (isPrime[i] == true) 
                cnt++;
        }
        return cnt;
    }
};