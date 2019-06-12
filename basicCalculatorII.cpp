class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0)  return 0;
        char op = 0;
        stack<int> num_stack;
        int i = 0;
        while (i < n) {
            if (s[i] == ' ')  i++;
            // 获得数字
            else if (s[i] >= '0' && s[i] <= '9') {
                num_stack.push(getNum(s, i));
            } else if (s[i] == '*') {
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = getNum(s, i);
                num_stack.push(num1*num2);
            } else if (s[i] == '/') {
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = getNum(s, i);
                num_stack.push(num1/num2);
            } else if (s[i] == '+' || s[i] == '-') {
                if (op == '+') {
                    int num2 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(num1+num2);
                } else if (op == '-') {
                    int num2 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(num1-num2);
                }
                op = s[i];
                i++;
            }
        }
        if (op == '+') {
            int num2 = num_stack.top();
            num_stack.pop();
            int num1 = num_stack.top();
            num_stack.pop();
            return num1 + num2;
        } else if (op == '-') {
            int num2 = num_stack.top();
            num_stack.pop();
            int num1 = num_stack.top();
            num_stack.pop();
            return num1 - num2;
        }
        return num_stack.top();
    }
    
    int getNum(string &s, int &i) {
        while (s[i] < '0' || s[i] > '9') i++;
        int num = s[i] - '0';
        i++;
        while (s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        return num;
    }
};