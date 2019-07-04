struct my_struct {
public:
    int num;
    int last_num;
    int n;
    my_struct(int _num, int _last_num, int _n): num(_num), last_num(_last_num), n(_n) {}
};

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ret;
        if (N == 1) {
            for (int i = 0; i <= 9; ++i)  ret.push_back(i);
            return ret;
        }
        queue<my_struct> my_queue;
        for (int i = 1; i <= 9; ++i) {
            my_queue.push(my_struct(i, i, 1));
        }
        while (!my_queue.empty()) {
            my_struct tmp = my_queue.front();
            my_queue.pop();
            int num = tmp.num;
            int n = tmp.n;
            int last_num = tmp.last_num;
            if (last_num - K >= 0) {
                int new_num = num * 10 + last_num - K;
                if (n + 1 == N)  ret.push_back(new_num);
                else  my_queue.push(my_struct(new_num, last_num - K, n + 1));
            }
            if (K != 0 && last_num + K < 10) {
                int new_num = num * 10 + last_num + K;
                if (n + 1 == N)  ret.push_back(new_num);
                else  my_queue.push(my_struct(new_num, last_num + K, n + 1));
            }
        }
        return ret;
    }
};