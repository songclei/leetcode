class Solution {
public:
    string decodeString(string s) {
        stack<int> count_stack;
        stack<string> string_stack;
        int l = s.length();
        if (l == 0)  return "";
        int i = 0;
        while (i < l) {
            //cout << s[i] << endl;
            // this is a number(count), so put the number to the count_stack
            if (s[i] >= '0' && s[i] <= '9') {
                string num;
                while (i < l && s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                //cout << num << endl;
                count_stack.push(atoi(num.c_str()));
            }
            else if (s[i] == '[') {
                string_stack.push("[");
                i++;
            }
            // fetch all the char between [ and ], and repeat it 
            else if (s[i] == ']') {
                string cur_s = string_stack.top();
                string_stack.pop();
                string_stack.pop();
                int num = count_stack.top();
                count_stack.pop();
                //cout << num << " " << cur_s << endl;
                string r_s;
                for (int j = 0; j < num; ++j) {
                    r_s += cur_s;
                }
                if (!string_stack.empty() && string_stack.top() != "[") {
                    r_s = string_stack.top() + r_s;
                    string_stack.pop();
                }
                string_stack.push(r_s);
                i++;
            }
            // if the char_stack is empty, means that the char does not to be repeated. add it directly to ret string. otherwise, push it
            else {
                string cur_s;
                while (i < l && s[i] != '[' && s[i] != ']' && !(s[i] >= '0' && s[i] <= '9')) {
                    cur_s += s[i];
                    i++;
                }
                // cout << cur_s << endl;
                if (!string_stack.empty() && string_stack.top() != "[") {
                    cur_s = string_stack.top() + cur_s;
                    string_stack.pop();
                }
                string_stack.push(cur_s);
            }
        }
        return string_stack.top();
    }
};