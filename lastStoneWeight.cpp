class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> my_queue;
        int n = stones.size();
        for (int i = 0; i < n; ++i) {
            my_queue.push(stones[i]);
        }
        while (my_queue.size() != 0 && my_queue.size() != 1) {
            int w1 = my_queue.top();
            my_queue.pop();
            int w2 = my_queue.top();
            my_queue.pop();
            if (w1 != w2)  my_queue.push(w1-w2);
        }
        if (my_queue.size() == 0)  return 0;
        else  return my_queue.top();
    }
};