#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#define min(a, b) a>b?(b):(a)
#define max(a, b) a>b?(a):(b)
#define MAX 100010
#define INF 0x7fffffff

using namespace std;

int n, m;
int tree[MAX], tree2[MAX];
int arr[MAX];
int tree_2[MAX], tree2_2[MAX];

void update(int i, int x) { // root 값이 n인 구조
	int t = i;
	while (i <= n) {
		tree[i] = min(tree[i], x);
		tree_2[i] = max(tree_2[i], x);
		i += (i & -i);
	}

	i = t - 1;
	while (i > 0) {		// 어차피 중복 i=0 인경우는 빼도 된다.
		tree2[i] = min(tree2[i], x);
		tree2_2[i] = max(tree2_2[i], x);
		i -= (i & -i);
	}
}

pair<int, int> query(int a, int b) {	// 탐색
	int v = INF;
	int v2 = 0;
	int cur, next;
	if (a > 1) {
		cur = a - 1;
		next = cur + (cur & -cur);
		while (next - 1 <= b - 1) {
			v = min(v, tree2[cur]);
			v2 = max(v2, tree2_2[cur]);
			cur = next;
			next = cur + (cur & -cur);
		}
	}

	cur = b;			// 왼쪽으로 가는거? 
	next = cur - (cur & -cur);
	while (next + 1 >= a) {
		v = min(v, tree[cur]);
		v2 = max(v2, tree_2[cur]);
		if (next == 0) break;				// 0놈은 특수 처리 해줘야한다. (0은 무한 루프를 유발한다.)
		cur = next;
		next = cur - (cur & -cur);
	}

	return pair<int, int> (v, v2);
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
		pair<int, int> ans = query(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}