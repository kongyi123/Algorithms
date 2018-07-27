// ³Ü»ö½Ä ´ÙÀÌ³ª¹Í

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int dy[4][1100];

int main(void) {
	int sum = 0;
	for (int i = 1;i <= 200;i++) {
		sum = sum + i;
		if (sum > 1000) break;
		dy[1][sum] = 1;
		for (int j = 1;j <= 2;j++) {
			for (int k = 1;k <= 1000;k++) {
				if (k + sum > 1000) break;
				if (dy[j][k]) dy[j+1][k + sum] = 1;
			}
		}
	}

	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		fprintf(stdout, "%d\n", dy[3][data]);
	}
	return 0;
}