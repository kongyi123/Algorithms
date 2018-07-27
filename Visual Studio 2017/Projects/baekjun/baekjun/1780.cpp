#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[3000][3000];
int n;

int cnt[10];

int back(int sy, int sx, int ey, int ex) {
	if (sy == ey && sx == ex) return data[sy][sx];

	int ty = (ey - sy + 1)/3;
	int tx = (ex - sx + 1)/3;
	int ey1 = sy+ty; // 3
	int ey2 = ey1+ty;			 // 6
	int ex1 = sx+tx; // 3
	int ex2 = ex1+tx;           // 6

	int a, b, c, d, e, f, g, h, i;
	a = back(sy, sx, ey1 - 1, ex1 - 1);
	b = back(sy, ex1, ey1 - 1, ex2 - 1);
	c = back(sy, ex2, ey1 - 1, ex);

	d = back(ey1, sx, ey2 - 1, ex1 - 1);
	e = back(ey1, ex1, ey2 - 1, ex2 - 1);
	f = back(ey1, ex2, ey2 - 1, ex);

	g = back(ey2, sx, ey, ex1 - 1);
	h = back(ey2, ex1, ey, ex2 - 1);
	i = back(ey2, ex2, ey, ex);


	if (a == b && b == c && c == d && d == e && e == f && f == g && g == h && h == i && a != 2) return a;
	else {
		cnt[a+1]++;
		cnt[b+1]++;
		cnt[c+1]++;
		cnt[d+1]++;
		cnt[e+1]++;
		cnt[f+1]++;
		cnt[g+1]++;
		cnt[h+1]++;
		cnt[i+1]++;
		return 2;
	}
}

int main(void) {
	int i, j;
	fscanf(stdin, "%d", &n);
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			fscanf(stdin, "%d", &data[i][j]);
		}
	}

	int result = back(0, 0, n - 1, n - 1);
	if (result != 2) cnt[result] ++;

	for (int i = 0;i <= 2;i++) fprintf(stdout, "%d\n", cnt[i]);
	
	return 0;
}