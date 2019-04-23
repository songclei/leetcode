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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)  return true;
        int len = 0;
        ListNode *slow = head;
        ListNode* fast = head;
        stack<int> my_stack;
        while (fast != NULL && fast->next != NULL) {
            my_stack.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != NULL)  slow = slow->next;
        while (!my_stack.empty() && slow != NULL) {
            if (slow->val != my_stack.top())  return false;
            slow = slow->next;
            my_stack.pop();
        }
        return true;
    }
};