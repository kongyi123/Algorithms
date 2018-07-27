#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int data;
	int cnt = 0;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data);
		if (i != data) cnt++;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}