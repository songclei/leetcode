/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)  return root;
        Node *tmp = root;
        Node *n = root;
        while (tmp) {
            // 只有叶子节点才没有孩子
            if (tmp == n)
                n = tmp->left;
            if (tmp->left == NULL)  break;
            tmp->left->next = tmp->right;
            // 没有兄弟的节点，其右子节点也无兄弟
            if (tmp->next != NULL)  tmp->right->next = tmp->next->left;
            if (tmp->next)  tmp = tmp->next;
            else  tmp = n;
        }
       /* while (t) {
            Node *p = t;
            t = t->left;
            while (p) {
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;
        }*/
        return root;
    }
};