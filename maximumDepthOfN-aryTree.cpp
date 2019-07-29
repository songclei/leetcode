/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)  return 0;
        int n = (root->children).size();
        if (n == 0)  return 1;
        int maxChildDepth = 0;
        for (int i = 0; i < n; ++i) {
            maxChildDepth = max(maxChildDepth, maxDepth((root->children)[i]));
        }
        return maxChildDepth + 1;
    }
};