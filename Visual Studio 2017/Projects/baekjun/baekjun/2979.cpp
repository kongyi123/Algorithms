#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int s[10];
int e[10];

int main(void) {
	int a, b, c;
	int cnt[4];
	cnt[0] = 0;
	fscanf(stdin, "%d %d %d", &cnt[1], &cnt[2], &cnt[3]);
	for (int i = 1;i <= 3;i++) {
		fscanf(stdin, "%d %d", &s[i], &e[i]);
	}

	int sum = 0;
	for (int i = 1;i <= 100;i++) {
		int count = 0;
		for (int j = 1;j <= 3;j++) {
			if (s[j] <= i && i + 1 <= e[j]) {
				count++;
			}
		}
		sum = sum + cnt[count]*count;
	}

	fprintf(stdout, "%d", sum);
	return 0;
}