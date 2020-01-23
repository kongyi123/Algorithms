#include <vector>

using namespace std;

#define NULL 0 

 struct ListNode {
     int val;
     ListNode *next;
	 ListNode() {
		 val = 0;
		 next = 0;
	 }
     ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
	
public:
	int tree[500], src[500];
	ListNode* ptr[500];
	int k;
	

	ListNode* mergeKLists(vector<ListNode*>& lists) {	
		int n = lists.size();
		if (n == 0) return 0;
		for (int i = 0; i < 500; i++)
			tree[i] = 200000000;
		
		for (k = 1; k < n; k <<= 1);
		for (int i = 0; i < n; i++) {
			if (lists[i] == 0) continue;
			tree[k + i] = lists[i]->val;
			src[k + i] = i;
			ptr[i] = lists[i];
		}

		for (int i = k - 1; i >= 1; i--) {
			if (tree[i * 2] < tree[i * 2 + 1]) {
				tree[i] = tree[i * 2];
				src[i] = src[i * 2];
			}
			else {
				tree[i] = tree[i * 2 + 1];
				src[i] = src[i * 2 + 1];
			}
		}
		
		ListNode *head, *tail;
		head = tail = 0;
		while (1) {
			int temp = src[1];
			if (tree[1] == 200000000) break;
			
			if (head == 0) {
				head = tail = ptr[src[1]];
				ptr[src[1]] = ptr[src[1]]->next;
			}
			else {
				ListNode* tNode = ptr[src[1]];
				ptr[src[1]] = ptr[src[1]]->next;
				tail->next = tNode;
				tail = tail->next;
			}
			if (ptr[temp] != NULL) {
				update(temp, ptr[temp]->val);
			}
			else {
				update(temp, 200000000);
			}
		}
		return head;
		
	}

	void update(int i, int val) {
		tree[k + i] = val;
		src[k + i] = i;
		int tmp = (k + i) / 2;
		while (tmp > 0) {
			if (tree[tmp * 2] < tree[tmp * 2 + 1]) {
				tree[tmp] = tree[tmp * 2];
				src[tmp] = src[tmp * 2];
			}
			else {
				tree[tmp] = tree[tmp * 2 + 1];
				src[tmp] = src[tmp * 2 + 1];
			}			
			tmp >>= 1;
		}
	}
};

int main(void) {
	Solution sol;
	vector<ListNode*> lists;

	sol.mergeKLists(lists);

	return 0;
}