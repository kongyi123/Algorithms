#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m;
int data[110][2];
int dy[110];

int main(void) {
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		fscanf(stdin, "%d%d", &data[i][0], &data[i][1]);
	}

	int i, j;
	for (i = 1;i <= m;i++) {
		for (j = i + 1;j <= m;j++) {
			if (data[i][0] > data[j][0]) {
				for (int k = 0;k <= 1;k++) {
					int t = data[i][k];
					data[i][k] = data[j][k];
					data[j][k] = t;
				}
			}	
		}
	}

	int dap = -1;
	for (i = 1;i <= m;i++) {
		int max = 0;
		for (j = 1;j <= i - 1;j++) {
			if (data[i][1] > data[j][1] && max < dy[j]) {
				max = dy[j];
			}
		}
		dy[i] = max + 1;
		if (dap < dy[i]) dap = dy[i];
	}

	fprintf(stdout, "%d", m-dap);


	return 0;
}