#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

int data[22];
int dy[11000];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n;
		fscanf(stdin, "%d", &n);
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d", &data[j]);
		}

		int tar;
		fscanf(stdin, "%d", &tar);

		for (int j = 1;j <= n;j++) {
			dy[data[j]] ++;
			for (int k = 1;k <= tar;k++) {
				if (k + data[j] > 10000) break;
				if (dy[k] != 0) dy[k + data[j]] = dy[k + data[j]] + dy[k];
			}
		}


		fprintf(stdout, "%d\n", dy[tar]);
		memset(dy, 0, sizeof(dy));
	}
	return 0;
}