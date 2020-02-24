#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[1000005];
int dy[1000005][2];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main(void) {
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0;
	int p = 1;
	for (int i = len-1; i >= 0; i--) {
		int val = str[i] - '0';
		if (i == len - 1) {
			dy[p][0] = val;
			dy[p][1] = 10 - val;
			p++;
		}
		else {
			dy[p][0] = min(val + dy[p - 1][0], val + 1 + dy[p - 1][1]);
			dy[p][1] = min(10 - val + dy[p - 1][0], abs(-(10 - val) + 1) + dy[p - 1][1]);
			p++;
		}
	}

	printf("%d", min(dy[len][0], dy[len][1] + 1));
	return 0;
}