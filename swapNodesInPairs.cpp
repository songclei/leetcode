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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *ret = head->next;
        ListNode *p = head;
        ListNode *q;
        while (p != NULL && p->next != NULL) {
            q = p->next;
            ListNode *tmp = q->next;
            if (q->next && q->next->next)
                p->next = q->next->next;
            else 
                p->next = q->next;
            q->next = p;
            p = tmp;
        }
        return ret;
    }
};