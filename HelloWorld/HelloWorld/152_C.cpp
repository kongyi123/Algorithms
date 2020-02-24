#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n;
	int min = 2000000000;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int dat;
		scanf("%d", &dat);
		if (min > dat) {
			min = dat;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}