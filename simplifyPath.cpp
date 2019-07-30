class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> my_stack;
        int i = 0, j = 0;
        while (i < n && j < n) {
            j = i + 1;
            while (j < n && path[j] != '/')  ++j;
            string s = path.substr(i+1, j-i-1);
            //cout << s << endl;
            if (s == "..") {
                if (!my_stack.empty())
                    my_stack.pop();
            }
            else if (s != "." && s.length() > 0)  my_stack.push(s);
            i = j;
        }
        string ret;
        while (!my_stack.empty()) {
            ret = "/" + my_stack.top() + ret;
            my_stack.pop();
        }
        if (ret.length() == 0)  ret = "/";
        return ret;
    }
};