#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	long long  r, c, n;
	long long t1, t2;
	fscanf(stdin, "%lld %lld %lld", &r, &c, &n);
	t1 = r / n;
	if (r % n > 0) t1++;
	t2 = c / n;
	if (c % n > 0) t2++;

/*	t1 = (long long)(r / n * 10);
	if (t1 % 10 > 0) t1 = t1 / 10 + 1;
	else t1 = t1 / 10;
	
	t2 = (long long)(c / n * 10);
	if (t2 % 10 > 0) t2 = t2 / 10 + 1;
	else t2 = t2 / 10;
*/

	fprintf(stdout, "%lld", t1*t2);
	return 0;
}