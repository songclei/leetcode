#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int > m;
        int size = nums.size();
        if (size == 0)
        	return 0;
        int length = 0;
        bool visited[size];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < size; ++i) {
        	m.insert(make_pair(nums[i], i));
        }
        for (int i = 0; i < size; i++) {
        	int l = 1;
        	if (visited[i]) 
        		continue;
        	visited[i] = true;
        	int n = nums[i] + 1;
        	unordered_map<int, int>::iterator it; 
        	while ((it = m.find(n)) != m.end()) {
        		l++;
        		visited[(*it).second] = true;
        		n++;
        	}
        	n = nums[i] - 1;
        	while ((it = m.find(n)) != m.end()) {
        		l++;
        		visited[(*it).second] = true;
        		n--;
        	}
        	if (l > length) length = l;
        }
        return length;
    }
};

int main() {
	Solution solu;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	cout << solu.longestConsecutive(nums) << endl;
	return 0;
}