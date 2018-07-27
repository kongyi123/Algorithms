#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n;
		int min = 200;
		int max = -1;
		fscanf(stdin, "%d", &n);
		for (int j = 1;j <= n;j++) {
			int data;
			fscanf(stdin, "%d", &data);
			if (min > data) min = data;
			if (max < data) max = data;
		}
		fprintf(stdout, "%d\n", (max - min)*2);
	}
	return 0;
}