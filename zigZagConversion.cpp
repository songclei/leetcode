class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int n;
        int i = 0;
        int l = s.length();
        while (i < l) {
        	for (n = 0; n < numRows; ++n) {
        		if (i >= l)  break;
        		v[n] += s[i];
        		i++;
        	}
        	for (n = numRows - 2; n >= 1; n--) {
        		if (i >= l)  break;
        		v[n] += s[i];
        		i++;
        	}
        }
        string ret;
        for (i = 0; i < numRows; ++i)
        	ret += v[i];
        return ret;
    }
};