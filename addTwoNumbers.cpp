#include <iostream>
#include <string>
#include <vector>
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
        if (l2 == NULL)  return l1;
        
        ListNode* ret;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* before;
        int carry = 0;
        while (p1 != NULL && p2 != NULL) {
        	int sum = p1->val + p2->val + carry;
        	if (sum > 9) {
        		sum = sum - 10;
        		carry = 1;
        	} else {
        		carry = 0;
        	}
        	p1->val = p2->val = sum;
        	before = p2;
        	p1 = p1->next;
        	p2 = p2->next;
        }
        ret = p1 != NULL ? l1 : l2;
        ListNode *p = p1 != NULL ? p1 : p2;
        if (p == NULL && carry == 1) {
        	before->next = new ListNode(1);
        }
        if (p != NULL && carry == 1) {
        	while (p != NULL && carry == 1) {
        		int sum = p->val + 1;
        		if (sum > 9) {
        			sum = sum - 10;
        			carry = 1;
        		} else {
        			carry = 0;
        		}
        		p->val = sum;
        		before = p;
        		p = p->next;
        	}
        	if (p == NULL && carry == 1) {
        		before->next = new ListNode(1);
        	}
        }
        return ret;
    }
};