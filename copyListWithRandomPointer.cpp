/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)  return NULL;
        unordered_map<Node*, Node*> my_map;
        Node *ret = new Node(head->val, NULL, head);
        ret->random = head;
        Node *p1 = head;
        Node *p2 = ret;
        while (p1->next != NULL) {
            p2->next = new Node(p1->next->val, NULL, p1->next);
            my_map[p2] = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = head;
        p2 = ret;
        while (p1 != NULL) {
            Node *tmp = p1->next;
            p1->next = p2;
            p1 = tmp;
            p2 = p2->next;
        }
        p1 = head;
        p2 = ret;
        while (p1 != NULL) {
            //cout << p1->val << endl;
            if (p1->random == NULL)  p2->random = NULL;
            else 
                p2->random = p1->random->next;
            if (p2->next != NULL)
                p1 = p2->next->random;
            else p1 = NULL;
            p2 = p2->next;
        }
        p1 = head;
        p2 = ret;
        while (p1 != NULL) {
            p1->next = my_map[p2];
            p1 = p1->next;
            p2 = p2->next;
        }
        return ret;
    }
};