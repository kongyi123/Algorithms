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

	for (int i = 9;i >= 0;i--) {
		for (int j = 1;j <= cnt[i];j++) {
			fprintf(stdout, "%d", i);
		}
	}
	return 0;
}
