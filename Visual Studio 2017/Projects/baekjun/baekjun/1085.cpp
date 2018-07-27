#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x, y, w, h;
	fscanf(stdin, "%d %d %d %d", &x, &y, &w, &h);
	int min = 20000;
	if (min > x) min = x;
	if (min > w - x) min = w - x;
	if (min > y) min = y;
	if (min > h - y) min = h - y;
	fprintf(stdout, "%d", min);
	return 0;
}