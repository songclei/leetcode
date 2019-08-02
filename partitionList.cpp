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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(-1);
        ListNode *big = new ListNode(-1);
        ListNode *p_small = small;
        ListNode *p_big = big;
        ListNode *p = head;
        while (p != NULL) {
           // cout << head->val << endl;
            if (p->val < x) {
                p_small->next = p;
                p_small = p_small->next;
            } else {
                p_big->next = p;
                p_big = p_big->next;
            }
            p = p->next;
        }
        if (p_small == small || p_big == big)  return head;
        p_small->next = big->next;
        p_big->next = NULL;
        return small->next;
    }
};