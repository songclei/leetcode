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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1)  return head;
        int cnt = 1;
        ListNode *p = head;
        ListNode *q = head;
        while (cnt < k && q != NULL) {
            q = q->next;
            cnt++;
        }
        if (cnt < k || q == NULL)  return head;
        ListNode *n = reverseKGroup(q->next, k);
        ListNode *p1 = p, *p2 = p->next, *p3 = p->next->next;
        while (p1 != q) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if (p3 != NULL) p3 = p3->next;
        }
        p->next = n;
        return q;
    }
};