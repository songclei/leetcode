class RecentCounter {
    int cnt;
    queue<int> pingQueue;
public:
    RecentCounter() {
        cnt = 0;
    }
    
    int ping(int t) {
        while (!pingQueue.empty()) {
            if (pingQueue.front() < t - 3000) {
                pingQueue.pop();
                cnt--;
            } else {
                break;
            }
        }
        pingQueue.push(t);
        cnt++;
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */