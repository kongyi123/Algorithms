#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int d[100];
int N;
int val;

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &d[i]);
	}
	scanf("%d", &val);

	int s = 1;
	int e = N;
	while (s <= e) {
		if (s == e) break;
		int mid = (s + e) / 2;
		if (d[mid] > val) e = mid;
		else s = mid + 1;
	}
	printf("%d\n", s);
	return 0;
}

