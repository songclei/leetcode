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
    void reorderList(ListNode* head) {
        // 将链表从中间分成两段
        if (head == NULL)  return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = slow->next;
        slow->next = NULL;
        p = reverseList(p);
        ListNode *q = head;
        while (p != NULL) {
            ListNode *nextp = p->next;
            ListNode *nextq = q->next;
            q->next = p;
            p->next = nextq;
            q = nextq;
            p = nextp;
        }
    }
    
    ListNode *reverseList(ListNode *head) {
        if (head == NULL)  return head;
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = NULL;
        return p;
    }
    
};