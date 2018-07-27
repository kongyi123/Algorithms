// 선택 정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[1100];

int main(void) {
	int i;
	int n;
	fscanf(stdin, "%d", &n);
	for (i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (data[i] > data[j]) {
				int t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
		}
	}

	for (i = 1;i <= n;i++) {
		fprintf(stdout, "%d\n", data[i]);
	}
	return 0;
}