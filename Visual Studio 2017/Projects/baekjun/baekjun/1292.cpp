#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;
	int cnt = 0;
	int sum = 0;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= 1000;i++) {
		for (int j = 1;j <= i;j++) {
			cnt++;
			if (n <= cnt && cnt <= m) sum = sum + i;
		}
	}
	fprintf(stdout, "%d", sum);
	return 0;
}