#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a>b?(b):(a)
#define MAX 1000
#define INF 0x7fffffff

int n, m;
int tree[MAX], tree2[MAX];
int arr[MAX];

void update(int i, int x) { // root 값이 n인 구조
	while (i <= n) {
		tree[i] = min(tree[i], x);
		i += (i & -i);
	}
}

void update2(int i, int x) { // root 값이 0인 구조
	while (i > 0) {
		tree2[i] = min(tree2[i], x);
		i -= (i & -i);
	}
}

int query(int a, int b) {	// 탐색
	int v = INF;
	int prev = a; // a -> b // blue
	int curr = prev + (prev & -prev);	
	while (curr <= b) {
		v = min(v, tree2[prev]);		
		prev = curr;
		curr = prev + (prev & -prev);
	}

	v = min(v, arr[prev]);

	prev = b;					    // b -> a // red
	curr = prev - (prev & -prev); 
	while (curr >= a) {			
		v = min(v, tree[prev]);
		prev = curr;						
		curr = prev - (prev & -prev);		
	}

	return v;
}


int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) 
		tree[i] = tree2[i] = INF;
	
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
		update2(i, arr[i]);
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a, b));
	}
}