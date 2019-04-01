#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > v;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end(), my_sort);
        int i = 0;
        int j = n - 1;
        int sum;
        while ((sum = v[i].first + v[j].first) != target) {
        	//cout << sum << endl;
            if (sum < target) i++;
            else j--;
        }
        vector<int> ret;
        ret.push_back(v[i].second);
        ret.push_back(v[j].second);
        return ret;
    }
    
    static bool my_sort(const pair<int, int> &a1, const pair<int, int> &a2) {
        return a1.first < a2.first;
    }
};

int main() {
	Solution solu;
	int n; 
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i)  cin >> num[i];
	int target;
	cin >> target;
	vector<int> ret = solu.twoSum(num, target);
	cout << ret[0] << " " << ret[1] << endl;
}
