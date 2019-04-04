class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        if (l == 0)  return true;
        stack<char> my_stack;
        int i = 0;
        while (i < l) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')  my_stack.push(s[i]);
            else {
                if (my_stack.empty())  return false;
                char tmp = my_stack.top();
                my_stack.pop();
                if (s[i] == ']' && tmp != '[' || s[i] == '}' && tmp != '{' || s[i] == ')' && tmp != '(')  return false;
            }
            i++;
        }
        if (my_stack.empty())  return true;
        else  return false;
    }
};