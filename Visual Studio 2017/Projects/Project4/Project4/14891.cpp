// 26Ка

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


char dat[4][8];
int K;
char t;

void rot(int num, int dir, int from) {
	int next = num + 1;
	int prev = num - 1;
	if ((from == 0 || from == 1) && next < 4 && dat[num][2] != dat[next][6]) rot(next, 1 - dir, 1);
	if ((from == 0 || from == 2) && prev > -1 && dat[num][6] != dat[prev][2]) rot(prev, 1 - dir, 2);

	if (dir == 1) {
		t = dat[num][7];
		for (int i = 7;i >= 1;i--) {
			dat[num][i] = dat[num][i - 1];
		}
		dat[num][0] = t;
	}
	else {
		t = dat[num][0];
		for (int i = 0;i <= 6;i++) {
			dat[num][i] = dat[num][i + 1];
		}
		dat[num][7] = t;
	}
}

int main(void) {
	int a, b;
	for (int i = 0;i <= 3;i++) {
		scanf("%s", dat[i]);
	}
	scanf("%d", &K);
	for (int i = 1;i <= K;i++) {
		scanf("%d %d", &a, &b);
		if (b == -1) b = 0;
		rot(a - 1, b, 0);
	}

	int score = 0;
	int pow = 1;
	for (int i = 0;i <= 3;i++) {
		score += (pow * (dat[i][0]-'0'));
		pow = pow * 2;
	}

	printf("%d", score);

	return 0;
}