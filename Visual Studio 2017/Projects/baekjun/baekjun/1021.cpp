#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int data[100];
int table[100][100];
int pos[100];

int main(void) {
	int i;
	fscanf(stdin, "%d %d", &n, &m);
	for (i = 1;i <= m;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (i = 1;i <= n;i++) {
		pos[i] = i;
		table[1][i] = i;
	}

	int dap = 0;
	int cnt = n;
	for (i = 1;i <= m;i++) {
		int temp = pos[data[i]];
		if ((cnt + 1) - temp > temp - 1) {
			dap += (temp - 1);
			int p = 0;
			for (int j = temp + 1;j <= cnt;j++) {
				table[i + 1][++p] = table[i][j];
			}
			for (int j = 1;j <= temp - 1;j++) {
				table[i + 1][++p] = table[i][j];
			}
			cnt = p;
			for (int j = 1;j <= cnt;j++) {
				pos[table[i + 1][j]] = j;
			}
		}
		else {
			dap += (cnt + 1) - temp;
			int p = 0;
			for (int j = temp + 1;j <= cnt;j++) {
				table[i + 1][++p] = table[i][j];
			}
			for (int j = 1;j <= temp - 1;j++) {
				table[i + 1][++p] = table[i][j];
			}
			cnt = p;
			for (int j = 1;j <= cnt;j++) {
				pos[table[i + 1][j]] = j;
			}
		}
	}

	fprintf(stdout, "%d", dap);
	return 0;
}
