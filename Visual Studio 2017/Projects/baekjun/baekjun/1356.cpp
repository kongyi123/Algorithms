#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[15], cnt;

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	while (n) {
		cnt++;
		num[cnt] = n % 10;
		n = n / 10;
	}

	int a, b;
	int yes = 0;
	for (int i = 1;i <= cnt-1;i++) {
		a = b = 1;
		for (int j = 1;j <= i;j++) {
			a = a * num[j];
		}
		for (int j = i + 1;j <= cnt;j++) {
			b = b * num[j];
		}

		if (a == b) yes = 1;
	}

	if (yes) fprintf(stdout, "YES");
	else fprintf(stdout, "NO");


	return 0;
}