struct my_compare {

    bool operator () (const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (n == 0)  return 0;
        vector<vector<int>> dis(n+1);
        for (int i = 0; i < n+1; ++i) dis[i].resize(n+1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (disEquels1(wordList[i], wordList[j])) {
                    dis[i][j] = 1;
                    dis[j][i] = 1;
                } else {
                    dis[i][j] = INT_MAX;
                    dis[j][i] = INT_MAX;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (disEquels1(beginWord, wordList[i])) {
                dis[i][n] = 1;
                dis[n][i] = 1;
            } else {
                dis[i][n] = INT_MAX;
                dis[n][i] = INT_MAX;
            }
        }
        /*
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (dis[i][j] == INT_MAX)  cout << -1 << " ";
                else  cout << dis[i][j] << " ";
            }
            cout << endl;
        }*/
        vector<bool> visited(n);
        int endWord_index = -1;
        for (int i = 0; i < n; ++i)
            if (endWord == wordList[i])  endWord_index = i;
        if (endWord_index == -1)  return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, my_compare> my_queue;
        for (int i = 0; i < n; ++i) {
            my_queue.push(make_pair(dis[n][i], i));
        }
        /*
        while (!my_queue.empty()) {
            pair<int, int> tmp = my_queue.top();
            my_queue.pop();
            int d = tmp.first;
            int index = tmp.second;
            cout << d << " " << index << endl;
        }*/
        // 算最小路径 
        while (!my_queue.empty()) {
            pair<int, int> tmp = my_queue.top();
            my_queue.pop();
            int d = tmp.first;
            int index = tmp.second;
            //cout << index << endl;
            if (visited[index]) continue;
            visited[index] = true;
            if (d == INT_MAX) break;
            for (int j = 0; j < n; ++j) {
                if (dis[index][j] != INT_MAX && (dis[n][j] == INT_MAX || dis[n][j] > dis[n][index]+dis[index][j])) {
                    dis[n][j] = dis[n][index] + dis[index][j];
                    my_queue.push(make_pair(dis[n][j], j));
                }
            }
        }
        if (dis[n][endWord_index] == INT_MAX)  return 0;
        else return dis[n][endWord_index] + 1;
    }
    
    bool disEquels1(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        if (l1 != l2) return false;
        int cnt = 0;
        for (int i = 0; i < l1; ++i) {
            if (word1[i] != word2[i]) {
                if (cnt == 0)  cnt++;
                else  return false;
            }
        }
        if (cnt == 0)  return false;
        return true;
    }
};