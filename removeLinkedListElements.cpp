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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *begin = new ListNode(-1);
        ListNode *p = begin;
        while (head != NULL) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            } else {
                p->next = NULL;
            }
            head = head->next;
        }
        return begin->next;
    }
};