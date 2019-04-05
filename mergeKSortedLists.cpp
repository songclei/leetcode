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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return NULL;
        ListNode* ret = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)  return l2;
        if (l2 == NULL)  return l1;
        ListNode* ret = new ListNode(0);
        ListNode* p = ret;
        while (l1 != NULL & l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != NULL)  p->next = l1;
        if (l2 != NULL)  p->next = l2;
        return ret->next;
    }
};