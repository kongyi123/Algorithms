#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

char a[23];
char b[23];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		fscanf(stdin, "%s %s", &a, &b);

		int len = strlen(a);
		fprintf(stdout, "Distances: ");
		for (int j = 0;j < len;j++) {
			if (a[j] <= b[j]) fprintf(stdout, "%d ", b[j] - a[j]);
			else fprintf(stdout, "%d ", b[j] + 26 - a[j]);
		}
		fprintf(stdout, "\n");
	}
	return 0;
}