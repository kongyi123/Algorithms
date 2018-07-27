#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int sum = 0;
	int min = 2000;
	for (int i = 1;i <= 7;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		if (data % 2 == 1) {
			if (min > data) min = data;
			sum = sum + data;
		}
	}

	if (sum == 0) fprintf(stdout, "-1");
	else fprintf(stdout, "%d\n%d", sum, min);
	return 0;
}