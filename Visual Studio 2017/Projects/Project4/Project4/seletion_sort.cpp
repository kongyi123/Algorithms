#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define MAX 1000000

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = 0;
	}
};

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main(void) {
	clock_t begin, end;
	Node* head, *tail;
	head = tail = 0;
	begin = clock();
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int dat;
		scanf("%d", &dat);
		if (i == 1) head = tail = new Node(dat);
		else tail = tail->next = new Node(dat);
	}

	Node* cur = head;
	for (int i = 1;i <= n-1;i++) {
		Node* iter = cur->next;
		for (int j = i + 1;j <= n;j++) {
			if (cur->data > iter->data) swap(cur->data, iter->data);
			iter = iter->next;
		}
		cur = cur->next;
	}

	cur = head;
/*	for (int i = 1;i <= n;i++) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}*/
	end = clock();
	printf("time = %d\n", end - begin);
	return 0;
}