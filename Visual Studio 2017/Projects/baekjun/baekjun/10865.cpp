#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int cnt[100010];

int main(void) {
	int a, b;
	fscanf(stdin, "%d %d", &n, &m);

	for (int i = 1;i <= m;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		cnt[a] ++;
		cnt[b] ++;
	}

	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%d\n", cnt[i]);
	}
	return 0;
}