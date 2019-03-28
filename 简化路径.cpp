#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> my_stack;
        int l = path.length();
        int i, j = 0;
        while (i < l && j < l) {
        	while (i < l && path[i] == '/') i++;
        	cout << path[i] << endl;
        	j = i;
        	while (j < l && path[j] != '/') j++;
        	if (i == l)  break;
        	cout << i << ' ' << j << endl;
        	string dir = path.substr(i, j-i);
        	//cout << dir << endl;
        	if (dir == ".") {}
        	else if (dir == "..") {
        		if (!my_stack.empty())
        			my_stack.pop();
        	}
        	else my_stack.push(dir);
        	i = j + 1;
        }
        if (my_stack.empty()) return "/";
        string ret;
        while (!my_stack.empty()) {
        	string dir = my_stack.top();
        	my_stack.pop();
        	ret.insert(0, dir);
        	ret.insert(0, 1, '/');
        }
        return ret;
    }
};

int main() {
	Solution solu;
	string s;
	cin >> s;
	cout << solu.simplifyPath(s) << endl;
}