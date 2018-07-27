#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[10];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	while (n) {
		cnt[n % 10] ++;
		n = n / 10;
	}

	int max = -1, t;
	for (int i = 0;i <= 9;i++) {
		if (i == 6 || i == 9) continue;
		if (max < cnt[i]) {
			max = cnt[i];
			t = i;
		}
	}

	if (max < (cnt[6] + cnt[9]+1) / 2) {
		max = (cnt[6] + cnt[9]+1) / 2;
	}

	fprintf(stdout, "%d", max);
	return 0;
}