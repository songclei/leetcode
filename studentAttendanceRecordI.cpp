class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        if (n <= 1)  return true;
        bool containA = false;
        int continousL = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                if (containA == true)  return false;
                else  containA = true;
                continousL = 0;
            } else if (s[i] == 'L') {
                if (continousL == 2)  return false;
                else continousL++;
            } else {
                continousL = 0;
            }
        }
        return true;
    }
}; 