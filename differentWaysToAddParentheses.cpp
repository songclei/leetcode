class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return _diffWaysToCompute(input, 0, input.size() - 1);
    }
    
    vector<int> _diffWaysToCompute(string input, int i, int j) {
        // cout << i << " " << j << endl;
        vector<int> ans;
        if (i > j)  return ans;
        for (int k = i; k <= j; ++k) {
            if (input[k] == '+' || input[k] == '-' || input[k] == '*') {
                vector<int> num1 = _diffWaysToCompute(input, i, k-1);
                vector<int> num2 = _diffWaysToCompute(input, k+1, j);
                for (int n1 = 0a; n1 < num1.size(); ++n1) {
                    for (int n2 = 0; n2 < num2.size(); ++n2) {
                        switch (input[k]) {
                            case '+':
                                ans.push_back(num1[n1] + num2[n2]);
                                break;
                            case '-':
                                ans.push_back(num1[n1] - num2[n2]);
                                break;
                            case '*':
                                ans.push_back(num1[n1] * num2[n2]);
                                break;
                        }
                    }
                }
            } 
        }
        // string[i-j]无operator
        if (ans.size() == 0) {
            ans.push_back(atoi(input.substr(i, j-i+1).c_str()));
        }
        return ans;
    }
};