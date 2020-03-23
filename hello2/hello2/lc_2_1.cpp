/**
Runtime: 28 ms, faster than 69.67% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Add Two Numbers.

Code Optimization
- remove /

*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result;
		ListNode* pivot = new ListNode((l1->val + l2->val) % 10);
		result = pivot;

		if ((l1->val + l2->val) >= 10 || l1->next != 0 || l2->next != 0) {
			if ((l1->val + l2->val) >= 10) pivot = pivot->next = new ListNode(1);
			else pivot = pivot->next = new ListNode(0);
		}


		while (l1->next && l2->next) {
			l1 = l1->next; l2 = l2->next;
			if ((l1->val + l2->val + pivot->val) >= 10 || l1->next != 0 || l2->next != 0) {
				if ((l1->val + l2->val + pivot->val) >= 10) pivot->next = new ListNode(1);
				else pivot->next = new ListNode(0);
			}
			pivot->val = (l1->val + l2->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		while (l1->next) {
			l1 = l1->next;
			if ((l1->val + pivot->val) >= 10 || l1->next != 0) {
				if ((l1->val + pivot->val) >= 10) pivot->next = new ListNode(1);
				else pivot->next = new ListNode(0);
			}

			pivot->val = (l1->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		while (l2->next) {
			l2 = l2->next;
			if ((l2->val + pivot->val) >= 10 || l2->next != 0) {
				if ((l2->val + pivot->val) >= 10) pivot->next = new ListNode(1);
				else pivot->next = new ListNode(0);
			}
			pivot->val = (l2->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		return result;
	}
};