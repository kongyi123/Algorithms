#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int w, h;
	int x, y;
	int t;
	fscanf(stdin, "%d %d %d %d %d", &w, &h, &x, &y, &t);
	if ((x + t) % (w * 2) <= w) fprintf(stdout, "%d ", (x + t) % (w * 2));
	else fprintf(stdout, "%d ", w * 2 - ((x + t) % (w * 2)));


	if ((y + t) % (h * 2) <= h) fprintf(stdout, "%d", (y + t) % (h * 2));
	else fprintf(stdout, "%d", h * 2 - ((y + t) % (h * 2)));

	
	//fprintf(stdout, "%d %d", (x+t)%)
	return 0;
}