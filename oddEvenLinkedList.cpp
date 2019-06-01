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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)  return head;
        ListNode *even_head = head->next;
        ListNode *even = even_head;
        ListNode *odd = head;
        while (even != NULL && odd != NULL) {
            if (even->next == NULL) {
                even->next = NULL;
                odd->next = even_head;
                break;
            } else {
                odd->next = even->next;
                odd = odd->next;
            }
            if (odd->next == NULL) {
                even->next = NULL;
                odd->next = even_head;
                break;
            } else {
                even->next = odd->next;
                even = even->next;
            }
        }
        return head;
    }
};