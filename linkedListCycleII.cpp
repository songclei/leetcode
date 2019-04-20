/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        unordered_set<ListNode*> my_set;
        while (p != NULL) {
            if (my_set.count(p) > 0)  return p;
            my_set.insert(p);
            p = p->next;
        }
        return NULL;
    }
};