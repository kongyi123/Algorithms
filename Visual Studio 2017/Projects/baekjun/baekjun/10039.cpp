#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int data;
	int sum = 0;
	for (int i = 1;i <= 5;i++) {
		fscanf(stdin, "%d", &data);
		if (data < 40) sum += 40;
		else sum += data;
	}

	fprintf(stdout, "%d", sum / 5);
	return 0;
}