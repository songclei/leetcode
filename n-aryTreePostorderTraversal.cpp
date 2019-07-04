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
    vector<int> postorder(Node* root) {
        vector<int> ret;
        _postorder(root, ret);
        return ret;
    }
    
    void _postorder(Node* root, vector<int> &vec) {
        if (root == NULL)  return;
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            _postorder(*it, vec);
        }
        vec.push_back(root->val);
    }
};