// top-down memoization ver.
// 점화식이 달라진다. 
// 완전히 반대 방향으로 바뀜

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dy[41][5];

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

int back(int a, int b) {
	if (a > N + 1) return 0;
	if (dy[a][b] != -1) return dy[a][b];
	if ((a == N+1 && b == 4) || (a == N && b == 2) || (a == N && b == 3)) return dy[a][b] = 1;

	switch (b) {
	case 0:
		return dy[a][b] = back(a + 1, 2);
		break;
	case 1:
		return dy[a][b] = back(a + 1, 3);
		break;
	case 2:
		return dy[a][b] = back(a + 1, 4) + back(a + 1, 0);
		break;
	case 3:
		return dy[a][b] = back(a + 1, 4) + back(a + 1, 1);
		break;
	case 4:
		return dy[a][b] = back(a + 2, 4) + back(a, 0) + back(a, 1);
		break;

	}
	
	return dy[a][b];
}

int main(void) {
	for (int i = 0;i < 40;i++) {
		for (int j = 0;j < 5;j++) {
			dy[i][j] = -1;
		}
	}

	scanf("%d", &N);
//  base value를 여기 넣어다 줘도 됨
//	dy[N][2] = dy[N][3] = dy[N + 1][4] = 1;
	if (N == 1) printf("0");
	else printf("%d", back(1, 4));
	return 0;
}