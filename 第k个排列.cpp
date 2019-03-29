#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> v;
	    int factorial[15];
	    factorial[0] = 1;
	    for (int i = 1; i < n; ++i) {
	    	factorial[i] = factorial[i-1] * i;
	    }
	    for (int i = 1; i <= n; ++i)
	    	v.push_back(i);
	    for (int i = n-1; i >= 1; --i) {
	    	int pos = (k-1) / factorial[i];
	    	k = k - pos * factorial[i];
	    	//cout << pos << ' ' << k << endl;
	    	vector<int>::iterator it = v.begin() + pos;
	    	ret.push_back((char)('0'+(*it)));
	    	v.erase(it);
	    	cout << v.size() << endl;
	    }
	    ret.push_back((char)('0'+v[0]));
	    return ret;
	}
};

int main() {
	Solution solu;
	int n;
	cin >> n;
	int k;
	cin >> k;
	cout << solu.getPermutation(n, k) << endl;
	return 0;
}