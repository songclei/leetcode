#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        int n = envelopes.size();
        if (n == 0)  return 0;
        sort(envelopes.begin(), envelopes.end(), my_sort);
        int longest_increasing[n];
        for (int i = 0; i < n; ++i)
        	longest_increasing[i] = 1;
        longest_increasing[0] = 1;
        for (int i = 1; i < n; ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (envelopes[i].second > envelopes[j].second && envelopes[i].first > envelopes[j].first) {
        			if (longest_increasing[i] < longest_increasing[j] + 1)
        				longest_increasing[i] = longest_increasing[j] + 1;
        		}
        	}
        }
        int max_env = 0;
        for (int i = 0; i < n; ++i) {
        	if (longest_increasing[i] > max_env)
        		max_env = longest_increasing[i];
        }
        return max_env;
    }

    static bool my_sort(const pair<int, int>& p1, const pair<int, int>& p2) {
    	if (p1.first == p2.first) 
    		return p1.second < p2.second;
    	else 
    		return p1.first < p2.first;
    }
};