// 25분까지 고민하다가 솔루션 검색해봄.
// 펜윅 트리문제인걸 알고도 솔루션도출을 못하겠다.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 110000

int tree[110000];
int cnt[110000];
int n;

void add(int i, int val) {
	while (i < MAX) {
		tree[i] += val;
		i = i + (i&-i);
	}
}

int sum(int i) {
	int tmp = 0;
	while (i > 0) {
		tmp += tree[i];
		i = i - (i&-i);
	}

	return tmp;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int ans = 0;
		int left, right;
		fscanf(stdin, "%d %d", &left, &right);
//		fprintf(stdout, "%d %d\n", sum(left), sum(right));
		ans += sum(left) + sum(right) - cnt[left] - cnt[right];
		cnt[left] = sum(left);
		cnt[right] = sum(right);
		add(left + 1, 1);
		add(right, -1);

		fprintf(stdout, "%d\n", ans);
	}

	return 0;
}