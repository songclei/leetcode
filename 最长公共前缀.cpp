#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
   		int size = strs.size();
   		if (size == 0)  return "";
   		string longestStr = strs[0];
   		for (int i = 1; i < size; ++i) {
   			int j = 0;
   			while (j < strs[i].length() && j < longestStr.length() && strs[i][j] == longestStr[j]) {
   				j++;
   			}
   			longestStr = longestStr.substr(0, j);
   		}
   		return longestStr;
    }
};

int main() {
	Solution solu;
	while (true) {
		string s;
		vector<string> strs;
		while (true) {
			cin >> s;
			if (s == "quit")  return 0;
			if (s == "end") break;
			strs.push_back(s);
		}
		cout << solu.longestCommonPrefix(strs) << endl;
	}
	return 0;
}