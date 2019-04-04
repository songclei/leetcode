class Solution {
    string num_map[15] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.length() == 0)  return ret;
        queue<pair<string, string> > my_queue;
        my_queue.push(make_pair(digits, ""));
        while (!my_queue.empty()) {
            pair<string, string> tmp = my_queue.front();
            my_queue.pop();
            string remaining_digits = tmp.first;
            string letter = tmp.second;
            if (remaining_digits.length() == 0)  ret.push_back(letter);
            else {
                int num = remaining_digits[0] - '0';
                string new_digits = remaining_digits.substr(1, remaining_digits.length()-1);
                string s;
                if (num == 0 || num == 1) {
                    s = letter;
                    my_queue.push(make_pair(new_digits, s));
                } else {
                    for (int i = 0; i < num_map[num].length(); ++i) {
                        s = letter + num_map[num][i];
                        my_queue.push(make_pair(new_digits, s));
                    }
                }
            }
        }
        return ret;
    }
};