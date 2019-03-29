#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <unordered_set>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (headA == NULL || headB == NULL)  return NULL;
        int l1 = 1;
        int l2 = 1;
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1->next != NULL) {
        	l1++;
        	p1 = p1->next;
        }
        while (p2->next != NULL) {
        	l2++;
        	p2 = p2->next;
        }
        if (p1 != p2)  return NULL;
        p1 = headA;
        p2 = headB;
        if (l1 > l2) {
        	for (int i = 0; i < l1 - l2; ++i) {
        		p1 = p1->next;
        	}
        }
        if (l1 < l2) {
        	for (int i = 0; i < l2 - l1; ++i) {
        		p2 = p2->next;
        	}
        } 
        while (p1 != p2) {
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return p1;
    }
};