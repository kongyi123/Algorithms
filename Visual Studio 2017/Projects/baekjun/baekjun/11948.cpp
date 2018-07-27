#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int sum = 0;
	int min = 999;
	for (int i = 1;i <= 4;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		sum = sum + data;
		if (min > data) min = data;
	}
	sum = sum - min;
	
	min = 999;
	for (int i = 1;i <= 2;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		sum = sum + data;
		if (min > data) min = data;
	}
	sum = sum - min;

	fprintf(stdout, "%d", sum);
	return 0;
}