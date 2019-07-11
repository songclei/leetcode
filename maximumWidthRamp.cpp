class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> leftStack;
        stack<int> rightStack;
        int n = A.size();
        if (n == 0)  return 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!leftStack.empty() && A[leftStack.top()] >= A[i])  leftStack.pop();
            leftStack.push(i);
            if (rightStack.empty() || A[rightStack.top()] < A[i])  rightStack.push(i);
        }
        int maxWidth = 0;
        while (!leftStack.empty() && !rightStack.empty()) {
            int left = leftStack.top();
            int right = rightStack.top();
            if (A[right] >= A[left]) {
                maxWidth = max(maxWidth, right - left);
                rightStack.pop();
            } else {
                leftStack.pop();
            }
        }
        return maxWidth;
    }
};