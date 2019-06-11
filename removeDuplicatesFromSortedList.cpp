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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)  return head;
        ListNode *p = head;
        while (p != NULL) {
            while (p->next != NULL && p->val == p->next->val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                delete(tmp);
            }
            p = p->next;
        }
        return head;
    }
};