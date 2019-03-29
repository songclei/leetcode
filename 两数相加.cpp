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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)  return l2;
        if (l2 == NULL)  return l2;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        while (p1 != NULL && p2 != NULL) {
        	int sum = p1->val + p2->val + carry;
        	if (sum >= 10) {
        		sum = sum - 10;
        		carry = 1;
        	} else {
        		carry = 0;
        	}
        	p1->val = sum;
        	p2->val = sum;
        	p1 = p1->next;
        	p2 = p2->next;
        }
        ListNode *ret = (p1 == NULL) ? l2 : l1;
        ListNode *p = (p1 == NULL) ? p2 : p1;
        while (p != NULL && carry) {
        	p->val += carry;
        	if (p->val >= 10) {
        		p->val -= 10;
        		carry = 1;
        	} else {
        		carry = 0;
        	}
        	p = p->next;
        }
        if (carry) {
        	p = ret;
        	while (p->next != NULL)
        		p = p->next;
        	p->next = new ListNode(carry);
        }
        return ret;
    }
};