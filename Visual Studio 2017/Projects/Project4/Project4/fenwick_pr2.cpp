#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int table2[20][20];
int table1[20][20];
int N = 16;

int find_y(int val) {
	int t = 1;
	for (int i = 1;i <= 100;i++) {
		t = t * 2;
		if (t == val) return i;
	}
	return 0;
}

void update1(int i) { // root 값이 0인 구조
	int index = i;
	while (i <= N) {
		printf("%d ", i);
		table1[i][index] = 1;
		i += (i & -i);
	}
	printf("\n");
}

void update2(int i) { // root 값이 0인 구조
	int index = i;
	while (i >= 0) {
		printf("%d ", i);
		table2[i][index] = 1;
		if (i == 0) break;
		i -= (i & -i);
	}
	printf("\n");
}


int main(void) {
	for (int i = 1;i <= 16;i++) {
		update1(i);
	}

	printf("\n");
	for (int i = 1;i <= 16;i++) {
		update2(i);
	}

	for (int i = 0;i <= 16;i++) {
		for (int j = 0;j <= 16;j++) {
			printf("%3d", table1[i][j]);
		}
		printf("\n");
	}	
	printf("\n");

	for (int i = 0;i <= 16;i++) {
		for (int j = 0;j <= 16;j++) {
			printf("%3d", table2[i][j]);
		}
		printf("\n");
	}

	return 0;
}
