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
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        vector<int > f(n);
        for (int i = 0; i < n; ++i)
        	f[i] = triangle[n-1][i];
        for (int i = n-2; i >= 0; --i) {
        	for (int j = 0; j <= i; ++j) {
        		f[j] = min(f[j], f[j+1]) + triangle[i][j];
        	}
        }
        return f[0];
    }
};