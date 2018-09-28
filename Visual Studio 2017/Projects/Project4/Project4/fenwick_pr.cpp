#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a>b?(b):(a)
#define MAX 1000
#define INF 0x7fffffff

int n, m;
int tree[MAX], tree2[MAX];
int arr[MAX];

void update(int i, int x) { // root ���� n�� ����
	int t = i;
	while (i <= n) {
		tree[i] = min(tree[i], x);
		i += (i & -i);
	}

	i = t - 1;
	while (i > 0) {		// ������ �ߺ� i=0 �ΰ��� ���� �ȴ�.
		tree2[i] = min(tree2[i], x);
		i -= (i & -i);
	}
}

int query(int a, int b) {	// Ž��
	int v = INF;
	int cur, next;
	if (a > 1) {
		cur = a - 1;
		next = cur + (cur & -cur);
		while (next-1 <= b-1) {
			v = min(v, tree2[cur]);
			cur = next;
			next = cur + (cur & -cur);
		}
	}

	cur = b;			// �������� ���°�? 
	next = cur - (cur & -cur);
	while (next+1 >= a) {
		v = min(v, tree[cur]);
		if (next == 0) break;				// 0���� Ư�� ó�� ������Ѵ�. (0�� ���� ������ �����Ѵ�.)
		cur = next;
		next = cur - (cur & -cur);
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
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a, b));
	}
}

