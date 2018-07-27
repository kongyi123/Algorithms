#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
	int a, b;
	int sum = 0;
	int max = 0;
	for (int i = 1;i <= 4;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		sum = sum - a + b;
		if (max < sum) max = sum;
	}

	fprintf(stdout, "%d", max);

	return 0;
}