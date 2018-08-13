#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int parent[1000001];

int find(int t) {
	if (t == parent[t]) 
		return t;
	
	return parent[t] = find(parent[t]);
}

void merge(int a, int b) {
	if (find(a) == find(b))
		return;
	
	parent[find(b)] = find(a);
}

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 1;i <= M;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		switch (a) {
		case 0:
			merge(b, c);
			break;
		case 1:
			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
			break;
		}
	}
	return 0;
}