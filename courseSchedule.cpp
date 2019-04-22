class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        if (n == 0)  return true;
        // number of in-degree
        vector<int> in_d(numCourses);
        // list of out-degree
        vector<vector<int>> out_d(numCourses);
        // number of node which has >= 1 in degree
        int nonempty_ind = 0;
        for (int i = 0; i < n; ++i) {
            int class1 = prerequisites[i].second;
            int class2 = prerequisites[i].first;
            if (in_d[class2] == 0)  nonempty_ind++;
            in_d[class2]++;
            out_d[class1].push_back(class2);
        }
        // list of node of in degree = 0
        queue<int> empty_node;
        for (int i = 0; i < numCourses; ++i) {
            if (in_d[i] == 0)
                empty_node.push(i);
        }
        while (!empty_node.empty()) {
            int i = empty_node.front();
            empty_node.pop();
            vector<int> out_degree = out_d[i];
            for (int j = 0; j < out_degree.size(); ++j) {
                cout << out_degree[j] << endl;
                if (--in_d[out_degree[j]] == 0) {
                    empty_node.push(out_degree[j]);
                    nonempty_ind--;
                }
            }
        }
        if (nonempty_ind == 0)  return true;
        else  return false;
    }
};