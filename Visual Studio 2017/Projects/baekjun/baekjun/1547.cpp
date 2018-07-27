#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ball[4];

int main(void) {
	int n;
	int a, b;
	fscanf(stdin, "%d", &n);
	ball[1] = 1;
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		int t = ball[a];
		ball[a] = ball[b];
		ball[b] = t;
	}

	for (int i = 1;i <= 3;i++) {
		if (ball[i] == 1) fprintf(stdout, "%d", i);
	}
	return 0;
}