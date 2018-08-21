// top-down memoization ver.
// 점화식이 달라진다. 
// 완전히 반대 방향으로 바뀜

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dy[41][8][8];
int check[41][4];

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

int back(int a, int b) {
	if (a > N + 1) return 0;
	if (b > 3) return back(a - 1, 1);

	if (a > N + 1) return 0;
	int order1, order2;
	order1 = order2 = 0;
	for (int i = 1;i <= 3;i++) {
		order1 |= (1 << check[a][i]);
		order2 |= (1 << check[a+1][i]);
	}
	
	if (dy[a][order1][order2] != -1) return dy[a][order1][order2];


	for (int i = a;i >= 1;i--) {
		for (int j = b;j <= 3;j++) {
			if (check[i][j] == 0 && check[i-1][j] == 0) {
				check[i][j] = check[i - 1][j] = 1;
				back(i, j);
				check[i][j] = check[i - 1][j] = 0;
			}

			if (j <= 2 && check[i][j] == 0 && check[i][j + 1] == 0) {
				
			}
		}
		b = 1;
	}


	switch (b) {
	case 0:
		return dy[a][order1][order2] = back(a + 1, 2);
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
	for (int i = 0;i < 8;i++) {
		dy[N][0][i] = 1;
		dy[N][3][i] = 1;
		dy[N][6][i] = 1;
	}
	
	
	if (N == 1) printf("0");
	else printf("%d", back(1, 3));
	return 0;
}