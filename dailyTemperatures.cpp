class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ret(n);
        if (n == 0)  return ret;
        stack<int> my_stack;
        for (int i = n - 1; i >= 0; --i) {
            if (my_stack.empty()) {
                ret[i] = 0;
            } else {
                while (!my_stack.empty()) {
                    if (T[my_stack.top()] > T[i]) {
                        ret[i] = my_stack.top() - i;
                        break;
                    }
                    my_stack.pop();
                }
            }
            if (my_stack.empty())  ret[i] = 0;
            my_stack.push(i);
        }
        return ret;
    }
};