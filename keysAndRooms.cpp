class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n <= 1)  return true;
        vector<bool> access(n);
        int accessCnt = 1;
        access[0] = true;
        queue<int> my_queue;
        my_queue.push(0);
        while (!my_queue.empty() && accessCnt < n) {
            int tmp = my_queue.front();
            my_queue.pop();
            int l = rooms[tmp].size();
            for (int i = 0; i < l; ++i) {
                if (access[rooms[tmp][i]] == false) {
                    accessCnt++;
                    access[rooms[tmp][i]] = true;
                    my_queue.push(rooms[tmp][i]);
                }
            }
        }
        if (accessCnt == n)  return true;
        else  return false;
    }
};