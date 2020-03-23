/*

Runtime: 32 ms, faster than 38.62% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Add Two Numbers.
*/


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode preHead(0), * p = &preHead;
		int extra = 0;
		while (l1 || l2 || extra) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next;
	}
};