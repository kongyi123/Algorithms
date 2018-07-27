#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int a, b, a2, b2;
	int cnt = 0;
	fscanf(stdin, "%d", &n);
	int cp = n;
	a = b = -1;
	while (1) {
		cnt++;
		a = n / 10;
		b = n % 10;
		a2 = b;
		b2 = (a + b) % 10;

		a = a2; b = b2;
		n = a*10 + b;
		if (cp == n) break;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}