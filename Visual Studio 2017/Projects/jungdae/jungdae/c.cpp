#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[210][3];
int table[51000][3], m;

int main(void) {
	int n, t;
	fscanf(stdin, "%d %d", &n, &t);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &data[i][0], &data[i][1]);
	}

	int max = 0;
	int cnt;
	int temp;
	m = 1;
	for (int i = 1;i <= n;i++) {
		cnt = 0;
		for (int j = 1;j <= m;j++) {
			temp = data[i][0] + table[j][0];
			if (temp <= t) {
				cnt++;
				table[m + cnt][0] = temp;
				table[m + cnt][1] = data[i][1] + table[j][1];
			}
		}

		m += cnt;
	}

	for (int i = 1;i <= m;i++) {
		if (max < table[i][1]) max = table[i][1];
	}

	fprintf(stdout, "%d", max);

	return 0;
}