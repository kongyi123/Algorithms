// 25. Reverse Nodes in k-Group
// 일단, 개수를 세어 보는 것은 필수 라는 것 까지 확인 - 필수적으로 해야되는 것을 확인
// 만든 것을 다시 이용할 생각을 해야함.
// 내이름으로 풀지 못하고 답안 확인하였음. 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next) return head;

		ListNode* count = head;
		for (int i = 1; i <= k-1; i++) {
			count = count->next;
			if (!count) return head;
		}

		ListNode* cur = head;
		ListNode* prev = 0;
		ListNode* next = head;
		for (int i = 1; i <= k; i++) {
			next = next->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}

		ListNode* afterK = reverseKGroup(cur, k);
		head->next = afterK;
		return prev;
	}

	
};


int main(void) {
	Solution sol;
	ListNode* head;
	ListNode* node;

	head = new ListNode(5);
	head->next = 0;
	for (int i = 4; i >= 1; i--) {
		node = new ListNode(i);
		node->next = head;
		head = node;
	}


	sol.reverseKGroup(head, 2);
	return 0;
}