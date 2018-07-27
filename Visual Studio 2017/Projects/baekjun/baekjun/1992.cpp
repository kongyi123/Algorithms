#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char data[100][100];
char dap[10000];
int dcnt;

int check(int sy, int sx, int ey, int ex) {
	for (int i = sy; i <= ey;i++) {
		for (int j = sx;j <= ex;j++) {
			if (data[i][j] != data[sy][sx]) {
				return -1;
			}
		}
	}

	return int(data[sy][sx] - '0');
}

int back(int sy, int sx, int ey, int ex) {
	if (sy == ey && sx == ex) return int(data[sy][sx] - '0');
	int t = check(sy, sx, ey, ex);
	if (t != -1) return t;
	else {
		int my = (sy + ey) / 2; // 4
		int mx = (sx + ex) / 2; // 4
		int a, b, c, d;

		dap[++dcnt] = '(';
		a = back(sy, sx, my, mx); if (a != 2) dap[++dcnt] = '0' + a;
		b = back(sy, mx + 1, my, ex); if (b != 2) dap[++dcnt] = '0' + b;
		c = back(my + 1, sx, ey, mx); if (c != 2) dap[++dcnt] = '0' + c;
		d = back(my + 1, mx + 1, ey, ex); if (d != 2) dap[++dcnt] = '0' + d;
		dap[++dcnt] = ')';
		return 2;
	}
}

int main(void) {
	int n;
	char buf[10];
	fscanf(stdin, "%d", &n);
	fgets(buf, sizeof(buf), stdin);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%c", &data[i][j]);
		}
		fgets(buf, sizeof(buf), stdin);
	}


	int t = check(1, 1, n, n);
	if (t != -1) fprintf(stdout, "%d", t);
	else back(1, 1, n, n);
	
	for (int i = 1;i <= dcnt;i ++) fprintf(stdout, "%c", dap[i]);

	return 0;
}