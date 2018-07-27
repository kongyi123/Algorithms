#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[1100];
int cnt[1100];

int main(void) {
	int n;
	int dap = 1;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	cnt[1] = 1;
	for (int i = 2;i <= n;i++) {
		int max = 1;
		for (int j = 1;j <= i - 1;j++) {
			if (data[j] > data[i]) {
				if (max < cnt[j]+1) {
					max = cnt[j]+1;
				}
			}
		}
		cnt[i] = max;
		if (dap < max)
			dap = max ;
	}
	
	fprintf(stdout, "%d", dap);
	return 0;
}