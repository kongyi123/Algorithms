#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, m, s;
	int h2, m2, s2;
	int cur, start;
	fscanf(stdin, "%d:%d:%d", &h, &m, &s); cur = h * 60 * 60 + m * 60 + s;
	fscanf(stdin, "%d:%d:%d", &h2, &m2, &s2); start = h2 * 60 * 60 + m2 * 60 + s2;

	if (cur > start) start = start + 60 * 60 * 24;

	start = start - cur;
	fprintf(stdout, "%02d:%02d:%02d", start / 3600, (start % 3600) / 60, start % 60);
	return 0;
}