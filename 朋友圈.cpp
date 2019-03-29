#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
    	int n = M.size();
        vector<bool> visited;
        visited.resize(n);
        for (int i = 0; i < n; ++i)
        	visited[i] = false;
        int circleNum = 0;
        for (int i = 0; i < n; ++i) {
        	if (!visited[i]) {
        		circleNum++;
        		findAllFriends(M, visited, i);
        	}
        }
        return circleNum;
    }

    void findAllFriends(vector<vector<int> >& M, vector<bool>& visited, int k) {
    	int n = M.size();
    	visited[k] = true;
    	queue<int> my_queue;
    	my_queue.push(k);
    	while (!my_queue.empty()) {
    		int t = my_queue.front();
    		my_queue.pop();
    		for (int i = 0; i < n; ++i) {
    			if (M[t][i] == 1 && !visited[i]) {
    				visited[i] = true;
    				my_queue.push(i);
    			}
    		}
    	}
    }
};

int main() {

}