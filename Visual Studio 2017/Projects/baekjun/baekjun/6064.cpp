#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b) {
	int temp;
	while (b) {
		temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}

int main(void) {
	int t;
	int m, n, x, y;
	int lcm;
	int a, b;
	int a2, b2;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d%d%d%d", &m, &n, &x, &y);
		lcm = n*m/gcd(m, n);
		a = m; b = x;
		a2 = n; b2 = y;
		int flag = 0;
		int j;
		for (j = b;j <= lcm;j = j + a) {
			if ((j - b2) % a2 == 0) {
				flag = 1; break;
			}
		}

		if (flag == 1) {
			fprintf(stdout, "%d\n", j);
		}
		else {
			fprintf(stdout, "-1\n");
		}
	}
	return 0;
}