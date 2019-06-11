class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        int l = max(la, lb);
        string sum;
        sum.resize(l);
        int i = la - 1;
        int j = lb - 1;
        int k = sum.length() - 1;
        while (i >= 0 && j >= 0) {
            sum[k--] = a[i--] + b[j--] - '0';
        }
        if (i >= 0) {
            while (i >= 0)  sum[k--] = a[i--];
        }
        if (j >= 0) {
            while (j >= 0)  sum[k--] = b[j--];
        }
        k = sum.length() - 1;
        bool carry = false;
        for (; k >= 0; --k) {
            if (carry == true)  sum[k]++;
            if (sum[k] >='2') {
                sum[k] -= 2;
                carry = true;
            } else {
                carry = false;
            }
        }
        if (carry == true) {
            sum = "1" + sum;
        }
        return sum;
    }
};