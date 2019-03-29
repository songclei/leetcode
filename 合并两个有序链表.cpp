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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if (l1 == NULL)  return l2;
        if (l2 == NULL)  return l1;
        ListNode* ret = NULL;
        ListNode* p = NULL;
        while (p1 != NULL && p2 != NULL) {
        	int val = 0;
        	if (p1->val < p2->val) {
        		val = p1->val;
        		p1 = p1->next;
        	} else {
        		val = p2->val;
        		p2 = p2->next;
        	}
        	if (ret == NULL) {
    			ret = new ListNode(val);
    			p = ret;
    		} else {
    			p->next = new ListNode(val);
    			p = p->next;
    		}
        }
        if (p1 != NULL) {
        	while (p1 != NULL) {
        		p->next = new ListNode(p1->val);
        		p = p->next;
        		p1 = p1->next;
        	}
        }
        if (p2 != NULL) {
			while (p2 != NULL) {
        		p->next = new ListNode(p2->val);
        		p = p->next;
        		p2 = p2->next;
        	}
        }
        return ret;
    }
}; 