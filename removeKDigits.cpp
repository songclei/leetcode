class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k)  return "0";
        int i = 0;
        int j = 0;
        string ans;
        while (k > 0) {
            if (n - i == k) {
                i = n;
                break;
            }
            char min_num = num[i];
            int min_index = i;
            for (j = i; j <= i + k; ++j) {
                if (num[j] < min_num) {
                    min_index = j;
                    min_num = num[j];
                }
            }
            // cout << min_index << endl;
            if (ans.length() != 0 || min_num != '0')
                ans += min_num;
            k -= min_index - i;
            i = min_index + 1;
        }
        ans += num.substr(i, num.length()-i);
        if (ans.length() == 0)  ans = "0";
        return ans;
    }
};