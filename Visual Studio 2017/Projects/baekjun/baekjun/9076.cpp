#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[6];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		for (int j = 1;j <= 5;j++) {
			fscanf(stdin, "%d", &data[j]);			
		}

		for (int j = 1;j <= 5;j++) {
			for (int k = j + 1;k <= 5;k++) {
				if (data[j] < data[k]) {
					int t = data[j];
					data[j] = data[k];
					data[k] = t;
				}
			}
		}

		if (data[2] - data[4] >= 4) fprintf(stdout, "KIN\n");
		else fprintf(stdout, "%d\n", data[2] + data[3] + data[4]);
	}
	return 0;
}