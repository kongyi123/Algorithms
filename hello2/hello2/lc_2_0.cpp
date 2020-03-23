/**
Runtime: 32 ms, faster than 38.62% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Add Two Numbers.
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result;
		ListNode* pivot = new ListNode((l1->val + l2->val) % 10);
		result = pivot;

		if ((l1->val + l2->val) / 10 != 0 || l1->next != 0 || l2->next != 0)
			pivot = pivot->next = new ListNode((l1->val + l2->val) / 10);


		while (l1->next && l2->next) {
			l1 = l1->next; l2 = l2->next;
			if (!((l1->val + l2->val + pivot->val) / 10 == 0) || l1->next != 0 || l2->next != 0)
				pivot->next = new ListNode((l1->val + l2->val + pivot->val) / 10);
			pivot->val = (l1->val + l2->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		while (l1->next) {
			l1 = l1->next;
			if (!((l1->val + pivot->val) / 10 == 0) || l1->next != 0)
				pivot->next = new ListNode((l1->val + pivot->val) / 10);
			pivot->val = (l1->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		while (l2->next) {
			l2 = l2->next;
			if (!((l2->val + pivot->val) / 10 == 0) || l2->next != 0)
				pivot->next = new ListNode((l2->val + pivot->val) / 10);
			pivot->val = (l2->val + pivot->val) % 10;
			pivot = pivot->next;
		}

		return result;
	}
};