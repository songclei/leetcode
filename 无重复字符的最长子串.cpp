// ij初始指向string最开始，让j先移动到能移动到的最远距离，如果发现重复的，就停止移动j，开始移动i直到ij之间无重复字符串
// 用一个bool数组记录字符是否出现过，移动j时的字符标位true，移动i时恢复为false
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		if (n == 0) return 0; 
		int maxLength = 0;
		int i = 0, j = 0;
		bool exists[1000];
		memset(exists, 0, sizeof(exists));
	
		while (i <= j && j < n) {
			while (j < n && exists[s[j]] == false) {
				exists[s[j]] = true;
				j++;
			}
			int l = j - i;
			if (l > maxLength) maxLength = l;
			if (j == n)  return maxLength;
			
			while (i <= j && s[i] != s[j]) {
				exists[s[i]] = false;
				i++;
			}
			exists[s[i]] = false;
			i++;
		}
		return maxLength;
	}
};

int main() {
	Solution solu;
	string s;
	while (true) {
		cin >> s;
		if (s == "quit")  return 0;
		cout << solu.lengthOfLongestSubstring(s) << endl;
	}
	return 0;
}
