#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        int result[l1+l2+5];
        memset(result, 0, sizeof(result));
        for (int i = l1-1; i >= 0; i--) {
        	for (int j = l2-1; j >= 0; j--) {
        		result[l1+l2-i-j-2] += (num1[i]-'0') * (num2[j]-'0'); 
        	}
        }
        for (int i = 0; i < l1 + l2; ++i) {
        	if (result[i] >= 10) {
        		result[i+1] += result[i] / 10;
        		result[i] = result[i] % 10;
        	}
        }
        string ret;
        int i;
        for (i = l1+l2+4; i > 0; i--)
        	if (result[i] != 0)  break;
        /**
        for (; i >= 0; i--)
        	cout << result[i] << endl;
        exit(0);
        **/
        for(; i >= 0; i--)
        	ret.append(1,'0'+result[i]);
        return ret;
    }
};

int main() {
	Solution solu;
	string s1, s2;
	cin >> s1 >> s2;
	cout << solu.multiply(s1, s2) << endl;
}