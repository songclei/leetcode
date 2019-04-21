class MinStack {
    stack<int> min_stack;
    vector<int>  sort_list;
    int size;
public:
    /** initialize your data structure here. */
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        min_stack.push(x);
        int i = 0;
        while (i < size && sort_list[i] < x)  i++;
        sort_list.insert(sort_list.begin()+i, x);
        size++;
    }
    
    void pop() {
        if (size == 0)  return;
        int x = top();
        min_stack.pop();
        int i = 0;
        while (sort_list[i] != x)  i++;
        sort_list.erase(sort_list.begin()+i);
        size--;
    }
    
    int top() {
        if (size == 0)  return 0;
        return min_stack.top();
    }
    
    int getMin() {
        if (size == 0)  return 0;
        return sort_list[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */