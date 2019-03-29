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
    ListNode* reverseList(ListNode* head) {
    	if (head == NULL)  return NULL;
        ListNode *p = head;
        ListNode *ret = new ListNode(p->val);
        p = p->next;
        while (p != NULL) {
        	ListNode *tmp = new ListNode(p->val);
        	tmp->next = ret;
        	ret = tmp;
        	p = p->next;
        }
        return ret;
    }
};