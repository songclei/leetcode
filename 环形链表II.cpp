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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool first = true;
        bool exist = false;
        while (fast != NULL && fast->next != NULL) {
        	if (fast == slow) {
        		if (first)
        			first = false;
        		else {
        			exist = true;
        			break;
        		}	
        	}
        	slow = slow->next;
        	fast = fast->next->next;
        }
        if (!exist) return NULL;
        unordered_set<ListNode *> node_set;
        while (node_set.find(slow) == node_set.end()) {
        	node_set.insert(slow);
        	slow = slow->next;
        }
        ListNode* p = head;
        while (node_set.find(p) == node_set.end()) {
        	p = p->next;
        }
        return p;
    }
};