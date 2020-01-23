// 25. Reverse Nodes in k-Group
// �ϴ�, ������ ���� ���� ���� �ʼ� ��� �� ���� Ȯ�� - �ʼ������� �ؾߵǴ� ���� Ȯ��
// ���� ���� �ٽ� �̿��� ������ �ؾ���.
// ���̸����� Ǯ�� ���ϰ� ��� Ȯ���Ͽ���. 

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