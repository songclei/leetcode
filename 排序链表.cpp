#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

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
        ListNode *pre = head;
        while (fast != NULL && fast->next != NULL) {
        	pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL)  return l2;
    	if (l2 == NULL)  return l1;
    	ListNode* ret = new ListNode(0);
    	ListNode* p = ret;
    	while (l1 != NULL && l2 != NULL) {
    		if (l1->val < l2->val) {
    			p->next = l1;
    			l1 = l1->next;
    		} else {
    			p->next = l2;
    			l2 = l2->next;
    		}
    		p = p->next;
    	}
    	if (l1 != NULL) {
    		p->next = l1;
    	}
    	if (l2 != NULL) {
    		p->next = l2;
    	}
    	return ret->next;
    }
};
