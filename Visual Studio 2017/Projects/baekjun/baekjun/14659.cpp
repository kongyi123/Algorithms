#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[100001];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int max = -1;
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		if (max < data) max = data;
		cnt[max] ++;
	}

	int dap = -1;
	for (int i = 1;i <= 100000;i++) {
		if (dap < cnt[i]) {
			dap = cnt[i];
		}
	}

	fprintf(stdout, "%d", dap-1);
	return 0;
}