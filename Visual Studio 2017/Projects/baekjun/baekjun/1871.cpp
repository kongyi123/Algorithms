#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[110];

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &str);
		int a, b;
		a = b = 0;
		a = a + (str[0] - 'A') * 26 * 26;
		a = a + (str[1] - 'A') * 26;
		a = a + (str[2] - 'A');

		b = b + (str[4] - '0') * 10 * 10 * 10;
		b = b + (str[5] - '0') * 10 * 10;
		b = b + (str[6] - '0') * 10;
		b = b + (str[7] - '0');

		if (abs(a - b) <= 100) fprintf(stdout, "nice\n");
		else fprintf(stdout, "not nice\n");

		memset(str, 0, sizeof(str));
	}
	return 0;
}