#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;
	int data;
	fscanf(stdin, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data);
		if (data < m) fprintf(stdout, "%d ", data);
	}
	return 0;
}