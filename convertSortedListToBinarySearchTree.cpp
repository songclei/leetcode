/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)  return NULL;
        else if (head->next == NULL) return new TreeNode(head->val);
        else if (head->next->next == NULL) {
            TreeNode *p1 = new TreeNode(head->val);
            TreeNode *p2 = new TreeNode(head->next->val);
            p1->right = p2;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *before = NULL;
        while (fast != NULL && fast->next != NULL) {
            before = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        before->next = NULL;
        TreeNode *p = new TreeNode(slow->val);
        p->left = sortedListToBST(head);
        p->right = sortedListToBST(slow->next);
        return p;
    }
};