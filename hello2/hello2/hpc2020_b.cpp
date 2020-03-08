#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, m;
	int A[100005], B[100005];
	int min;
	scanf("%d%d%d", &a, &b, &m);
	int mina, minb;
	mina = minb = 2000000000;
	for (int i = 1; i <= a; i++) {
		scanf("%d", &A[i]);
		if (mina > A[i]) mina = A[i];
	}
	for (int i = 1; i <= b; i++) {
		scanf("%d", &B[i]);
		if (minb > B[i]) minb = B[i];
	}

	int x, y, c;
	if (m >= 1) {
		scanf("%d%d%d", &x, &y, &c);
		min = A[x] + B[y] - c;
		for (int i = 2; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &c);
			if (min > A[x] + B[y] - c)
				min = A[x] + B[y] - c;
		}
	}

	if (min > mina + minb) {
		min = mina + minb;
	}

	
	printf("%d", min);
	return 0;
}