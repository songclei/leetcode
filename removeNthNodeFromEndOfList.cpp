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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)  return NULL;
        int l = 0;
        vector<ListNode *> v;
        ListNode *p = head;
        while (p != NULL) {
            v.push_back(p);
            l++;
            p = p->next;
        }
        int remove_num = l - n;
        // remove head
        if (remove_num == 0)
            return head->next;
        else {
            v[remove_num-1]->next = v[remove_num]->next;
        }
        return head;
    }
};