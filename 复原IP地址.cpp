#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	int l = s.length();
    	vector<string> ret;
    	for (int i = 0; i < 3 && i < l-1; ++i) {
    		for (int j = i+1; j < i+4 && j < l-1; ++j) {
    			for (int k = j+1; k < j+4 && k < l-1; ++k) {
    				string sub1 = s.substr(0, i+1);
    				string sub2 = s.substr(i+1, j-i);
    				string sub3 = s.substr(j+1, k-j);
    				string sub4 = s.substr(k+1, l-k-1);
    				if (isIpNumber(sub1) && isIpNumber(sub2) && isIpNumber(sub3) && isIpNumber(sub4)) {
    					string s_copy = s;
    					s_copy.insert(i+1, 1, '.');
    					s_copy.insert(j+2, 1, '.');
    					s_copy.insert(k+3, 1, '.');
    					ret.push_back(s_copy);
    					cout << s_copy << endl;
    				}
    			}
    		}
    	}   
    	return ret;
    }

    bool isIpNumber(string s) {
    	if (s.length() > 1 && s[0] == '0') return false;
    	int num = atoi(s.c_str());
    	if (num >= 0 && num <= 255)
    		return true;
    	return false;
    }
};

int main() {
	Solution solu;
	string s;
	cin >> s;
	solu.restoreIpAddresses(s);
}