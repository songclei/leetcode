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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)  return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *before;
        while (fast != NULL && fast->next != NULL) {
            before = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        before->next = NULL;
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(slow);
        return merge(p1, p2);
    }
    
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (p1 == NULL)  return p2;
        if (p2 == NULL)  return p1;
        ListNode* ret = new ListNode(0);
        ListNode* p = ret;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        return ret->next;
    }
};