/*
Runtime: 32 ms, faster than 38.62% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Add Two Numbers.

*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0;
		ListNode* l3 = NULL;
		ListNode** node = &l3;
		while (l1 != NULL || l2 != NULL || sum > 0)
		{
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			(*node) = new ListNode(sum % 10);
			sum /= 10;
			node = &((*node)->next);
		}
		return l3;
	}
};