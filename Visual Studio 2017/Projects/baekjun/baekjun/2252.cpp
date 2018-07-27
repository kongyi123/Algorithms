#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int val;
} node;

node* adj[33000];
int cnt[33000];
int queue[110000], head = 0, tail = 0;

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		adj[i] = (node*)malloc(sizeof(node));
		adj[i]->next = 0;
		adj[i]->val = 0;
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		node* temp = (node*)malloc(sizeof(node));
		temp->next = adj[a];
		temp->val = b;
		adj[a] = temp;
		cnt[b] ++;
	}

	for (int i = 1;i <= n;i++) {
		if (cnt[i] == 0) {
			queue[tail++] = i;
		}	
	}

	while (head < tail) {
		int cur = queue[head];
		for (node* i = adj[cur];i->next != 0;i = i->next) {
			cnt[i->val] --;
			if (cnt[i->val] == 0) {
				queue[tail] = i->val;
				tail++;
			}
		}
		
		head++;
	}

	for (int i = 0;i < tail;i++) {
		fprintf(stdout, "%d ", queue[i]);
	}

	return 0;
}