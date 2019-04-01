#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        if (l == 0)  return 0;
        bool exist[150];
        memset(exist, 0, sizeof(exist));
        int max_length = 0;
        int i = 0;
        int j = 0;
        while (i < l && j < l) {
        	while (j < l && exist[s[j]] == false) {
        		exist[s[j]] = true;
        		j++;
        	}
        	int length = j - i;
        	if (length > max_length) max_length = length;
        	if (j == l)  return max_length;
        	while (s[i] != s[j]) {
        		exist[s[i]] = false;
        		i++;
        	}
        	exist[s[i]] = false;
        	i++;
        }
        return max_length;
    }
};

int main() {
	Solution solu;
	string s;
	cin >> s;
	cout << solu.lengthOfLongestSubstring(s) << endl;
}
