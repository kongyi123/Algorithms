/*
Runtime: 28 ms, faster than 69.67% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Add Two Numbers.
*/
class Solution {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* fake = new ListNode(0);
		ListNode* head = fake;
		int carry = 0;
		while (l1 != NULL || l2 != NULL) {
			int a = 0;
			int b = 0;
			if (l1 != NULL)
				a = l1->val;
			if (l2 != NULL)
				b = l2->val;
			int sum = a + b + carry;
			carry = sum / 10;
			head->next = new ListNode(sum % 10);
			head = head->next;
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;

		}
		if (carry > 0) {
			head->next = new ListNode(carry);
		}
		return fake->next;
	}
};