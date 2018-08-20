// 1:21
// 1. 유사한 기능을 한 함수로 처리하면 구현 속도가 빨라질 것이라고 생각하였음 (단번에 구현이 안되었을 때 디버깅할 양이 줄어들테니까)
// 2. 구현 설계시 방향을 고려한 슈도코를 작성하지 않고 한쪽 방향만 설계하였다가 헤매게됨
// 3. 뭔가 효율적인 방법을 찾으려고 하다가 N제한을 보고 단순히 코딩하기 쉬운 브루트 포스로 일일히 그림. (최악의 경우 시간복잡도만 만족한다면 굳이 효율성있게 이쁜 솔루션을 구할 필요 업다)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, L;
int table[110][110];
int dat[110][110];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int diff;

int make_road(int y, int x, int d) {
	// 한 행 또는 한 열에 +/-방향으로 만들 수 있는 곳에 내려가는 경사로를 만들어봄
	
	int ty, tx;
	for (int p = 2;p <= N;p++) {
		diff = dat[y][x] - dat[y - dir[d][0]][x - dir[d][1]];
		if (diff == -1) {
			ty = y; tx = x;
			for (int i = 0;i < L;i++) {
				if (ty > N || ty < 1) return -1;
				if (tx > N || tx < 1) return -1;
				if (table[ty][tx] == 1) return -1;
				if (dat[y][x] != dat[ty][tx]) return -1;
				ty += dir[d][0];
				tx += dir[d][1];
			}

			ty = y; tx = x;
			for (int i = 0;i < L;i++) {
				table[ty][tx] = 1;
				ty += dir[d][0];
				tx += dir[d][1];
			}
		}
		else if (diff >= 2) return -1;
		y += dir[d][0];
		x += dir[d][1];
	}

	return 1;
}

int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (make_road(i, 2, 0) != 1) continue;
		if (make_road(i, N-1, 1) != 1) continue;
		cnt++;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			table[i][j] = 0;
		}
	}

	for (int j = 1;j <= N;j++) {
		if (make_road(2, j, 2) != 1) continue;
		if (make_road(N-1, j, 3) != 1) continue;
		cnt++;
	}

	printf("%d", cnt);
		
	return 0;
}