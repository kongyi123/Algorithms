// bottom-up memoization ver.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dy[40][5];

int back(int a, int b) {
	if ((a == 1 && b == 2) || (a == 1 && b == 3) || (a == 0 && b == 4)) return 1; // base value
	if (a < 0) return 0;
	if (dy[a][b] != -1) return dy[a][b];
	else {
		switch (b) {
		case 0:
			return dy[a][b] = back(a - 1, 2);
			break;
		case 1:
			return dy[a][b] = back(a - 1, 3);
			break;
		case 2:
			return dy[a][b] = back(a - 1, 4) + back(a - 1, 0);
			break;
		case 3:
			return dy[a][b] = back(a - 1, 4) + back(a - 1, 1);
			break;
		case 4:
			return dy[a][b] = back(a - 2, 4) + back(a, 0) + back(a, 1);
			break;

		}
	}
	
}

int main(void) {
	for (int i = 0;i < 40;i++) {
		for (int j = 0;j < 5;j++) {
			dy[i][j] = -1;
		}
	}
	scanf("%d", &N);

	printf("%d", back(N, 4));
	return 0;
}