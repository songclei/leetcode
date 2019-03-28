#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	int l1 = s1.length();
    	int l2 = s2.length();
    	if (l1 > l2)  return false;
    	int charCount[30] = {0};
        for (int i = 0; i < l1; ++i) {
        	charCount[s1[i]-'a']--;
        	charCount[s2[i]-'a']++;
        }
        if (arrAllZero(charCount)) return true;
        for (int i = 1; i < l2-l1+1; ++i) {
        	charCount[s2[i-1]-'a']--;
        	charCount[s2[i+l1-1]-'a']++;
        	if (arrAllZero(charCount))  {
        		return true;
        	}
        }
        return false;
    }

    bool arrAllZero(int *a) {
    	for (char c = 'a'; c <= 'z'; ++c) {
    		if (a[c-'a'] != 0) {
    			return false;
    		}
    	}
    	return true;
    }
};

int main() {
	Solution solu;
	string s1;
	string s2;
	while (true) {
		cin >> s1;
		if (s1 == "quit")  return 0;
		cin >> s2;
		cout << solu.checkInclusion(s1, s2) << endl;
	}
	return 0;
}