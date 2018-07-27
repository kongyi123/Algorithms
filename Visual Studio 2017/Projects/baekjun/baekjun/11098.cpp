#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[30];
char dap[30];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n;
		int max;
		fscanf(stdin, "%d", &n);
		max = -1;
		for (int j = 1;j <= n;j++) {
			int val;
			fscanf(stdin, "%d %s", &val, &str);
			if (max < val) {
				max = val;
				strcpy(dap, str);
			}
			memset(str, 0, sizeof(str));
		}
		fprintf(stdout, "%s\n", dap);
		memset(dap, 0, sizeof(dap));
	}

	return 0;
}