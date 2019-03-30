#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;

class MinStack {
    vector<int> stack;
    vector<int> ordered_list;
    int size;

public:
    /** initialize your data structure here. */
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        stack.push_back(x);
        int i;
        for (i = 0; i < size; ++i) {
            if (ordered_list[i] > x) {
                auto it = ordered_list.begin() + i;
                ordered_list.insert(it, x);
                break;
            }
        }
        if (i == size)
            ordered_list.push_back(x);
        size++;
    }
    
    void pop() {
        if (size == 0)  return;
        auto it = stack.end() - 1;
        int x = *it;
        stack.erase(it);
        it = ordered_list.begin();
        for (it; it != ordered_list.end(); ++it)
            if (*it == x) {
                ordered_list.erase(it);
                break;
            }
        size--;
    }
    
    int top() {
        if (size == 0)  return 0;
        return stack[size-1];
    }
    
    int getMin() {
        if (size == 0)  return 0;
        return ordered_list[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */