#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n;
int table[100][100];
int max[100];

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			table[i][j] = 9999999;
		}
		table[i][i] = 0;
	}
	
	while (1) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		table[a][b] = table[b][a] = 1;
	}

	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (table[i][j] > table[i][k] + table[k][j])
					table[i][j] = table[i][k] + table[k][j];
			}
		}
	}

	int dap = 999;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (max[i] < table[i][j])
				max[i] = table[i][j];
		}
		if (dap > max[i])
			dap = max[i];
	}

	int dcnt = 0;
	for (int i = 1;i <= n;i++) {
		if (dap == max[i]) dcnt++;
	}

	fprintf(stdout, "%d %d\n", dap, dcnt);
	for (int i = 1;i <= n;i++) {
		if (dap == max[i]) fprintf(stdout, "%d ", i);
	}
	return 0;
}