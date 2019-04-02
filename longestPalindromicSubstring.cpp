class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        if (l == 0) return "";
        bool f[l][l];
        for (int i = 0; i < l; ++i)
       		f[i][i] = true;
       	for (int j = 1; j < l; ++j) {
       		for (int i = 0; i < l - j; ++i) {
       			if (s[i] != s[i+j])  f[i][i+j] = false;
       			else {
                    if (j == 1)  f[i][i+j] = true;
                    else f[i][i+j] = f[i+1][i+j-1];
                }
       		}
       	}
       	int l_x;
       	int l_y;
       	int max_length = 0;
       	for (int i = 0; i < l; ++i) {
       		for (int j = i; j < l; ++j) {
                //cout << "f[" << i << "][" << j << "] is : " << f[i][j] << endl;
       			if (f[i][j] == true && j-i+1 >= max_length) {
       				max_length = j - i + 1;
       				l_x = i;
       				l_y = j;
       			}
       		}
       	}
       	return s.substr(l_x, max_length);
    }
};