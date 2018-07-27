// 그냥 배열 사용법. 쌩기초

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int data[100100];
char dap[200100];
int st[100100], scnt;


int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int p = 1;
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (data[p] == st[scnt - 1]) {
			// pop
			dap[++cnt] = '-';
			scnt--;
			i--;
			p++;
			continue;
		}
		
		// push
		dap[++cnt] = '+';
		st[scnt++] = i;
	}

	data[n+1] = -1;
	while (data[p] == st[scnt - 1]) {
		dap[++cnt] = '-';
		scnt--;
		p++;
	}

	if (scnt > 0) {
		fprintf(stdout, "NO");
	}
	else {
		for (int i = 1;i <= cnt;i++) {
			fprintf(stdout, "%c\n", dap[i]);
		}
	}
	return 0;
}