#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if (grid.empty())  return 0;
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<bool> > visited;
        visited.resize(x);
        for (int i = 0; i < x; ++i) 
        	visited[i].resize(y);
        int maxArea = 0;
        for (int i = 0; i < x; ++i) {
        	for (int j = 0; j < y; ++j) {
        		if (grid[i][j] == 1 && !visited[i][j]) {
        			int area = areaBfs(grid, visited, i, j);
        			if (area > maxArea)
        				maxArea = area;
        		}
        	}
        }
        return maxArea;
    }

    int areaBfs(vector<vector<int> > grid, vector<vector<bool> > &visited, int i, int j) {
    	int x = grid.size();
        int y = grid[0].size();
        visited[i][j] = true;
        int area = 1;
        queue<pair<int, int> > my_queue;
        my_queue.push(make_pair(i, j));
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        while (!my_queue.empty()) {
        	pair<int, int> point = my_queue.front();
        	my_queue.pop();
        	for (int k = 0; k < 4; ++k) {
        		int new_x = point.first + dx[k];
        		int new_y = point.second + dy[k];
        		if (new_x < 0 || new_x >= x)  continue;
        		if (new_y < 0 || new_y >= y)  continue;
        		if (!visited[new_x][new_y] && grid[new_x][new_y] == 1) {
        			visited[new_x][new_y] = true;
        			area += 1;
        			my_queue.push(make_pair(new_x, new_y));
        		}
        	}
        }
        return area;
    }
};

int main() {
	return 0;
}