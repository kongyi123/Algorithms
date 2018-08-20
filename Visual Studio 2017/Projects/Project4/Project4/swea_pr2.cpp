#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define HM 26
#define WM 10

int H, W;
int mp[HM][WM];
unsigned char mm[HM][(1 << WM)][1 << WM];

int ma(int a, int b) { return a>b ? a : b; }

int cc(int x) {		// bitmask...같은
	int cn = 0;
	for (int i = 0; i<W;i++) {
		cn = (cn << 1);
		if (mp[x][i] == 2)
			cn++;
	}
	return cn;
}

int so2(int x, int y);
int so(int x) { // 여기서 x는 세로와 관련된 변수
	if (x == H)	// 마지막 줄이면 컷트
		return 0;
	int cn = cc(x);
	int cn1 = cc(x - 1);
	if (mm[x - 1][cn][cn1] == 0) {
		mm[x - 1][cn][cn1] = so2(x, 0);
	}
	return mm[x - 1][cn][cn1];
}

int so2(int x, int y) {
	int temp = 0;
	for (int i = y; i< W - 1; i++) {
		if (mp[x][i] == 0 && mp[x + 1][i] == 0 && mp[x][i + 1] == 0 && mp[x + 1][i + 1] == 0) {
			mp[x][i] = 2;
			mp[x + 1][i] = mp[x][i + 1] = mp[x + 1][i + 1] = 1;
			temp = ma(temp, so2(x, i) + 1);
			mp[x][i] = mp[x + 1][i] = mp[x][i + 1] = mp[x + 1][i + 1] = 0;
		}
	}
	temp = ma(temp, so(x + 1));
	return temp;
}

void in2(int x, int y);
void in(int x) {
	if (x == H)
		return;
	int cn = cc(x);
	int cn1 = cc(x - 1);
	if (mm[x - 1][cn][cn1] != 0) {
		mm[x - 1][cn][cn1] = 0;
		in2(x, 0);
	}
}

void in2(int x, int y) {
	for (int i = y; i< W - 1; i++) {
		if (mp[x][i] == 0 && mp[x + 1][i] == 0 && mp[x][i + 1] == 0 && mp[x + 1][i + 1] == 0) {
			mp[x][i] = 2;
			mp[x + 1][i] = mp[x][i + 1] = mp[x + 1][i + 1] = 1;
			in2(x, i);
			mp[x][i] = mp[x + 1][i] = mp[x][i + 1] = mp[x + 1][i + 1] = 0;
		}
	}
	in(x + 1);
}

int main() {
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t) {
		scanf("%d %d", &W, &H);
		for (int i = 0; i < W; i++)
			for (int j = 1;j<H + 1;j++)
				scanf("%d", &mp[j][i]);
		printf("#%d %d\n", t, so(1));
		in(1);
	}
	return 0;
}