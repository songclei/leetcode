class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return getString(S) == getString(T);
    }
    
    string getString(string s) {
        stack<char> my_stack;
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            if (s[i] == '#') {
                if (!my_stack.empty())  my_stack.pop();
            } else {
                my_stack.push(s[i]);
            }
        }
        string ret;
        while (!my_stack.empty()) {
            ret += my_stack.top();
            my_stack.pop();
        }
        return ret;
    }
};