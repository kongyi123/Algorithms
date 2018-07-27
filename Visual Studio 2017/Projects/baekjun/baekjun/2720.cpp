#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n;
	int data;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data);
		fprintf(stdout, "%d ", data / 25);
		data = data % 25;
		fprintf(stdout, "%d ", data / 10);
		data = data % 10;
		fprintf(stdout, "%d ", data / 5);
		data = data % 5;
		fprintf(stdout, "%d\n", data / 1);
	}
	return 0;
}