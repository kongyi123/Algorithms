// 로봇 청소기
// 오토마타

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[52][52];
int visited[52][52];
int forward[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };

int back(int r, int c, int d, int cnt) {
	int left = d;

	for (int i = 1;i <= 4;i ++) {
		left--;
		if (left == -1) left = 3;

		int nr = r + forward[left][0];
		int nc = c + forward[left][1];
		if (data[nr][nc] == 0 && visited[nr][nc] == 0) {
			visited[nr][nc] = 1;
			return back(nr, nc, left, cnt + 1);
		}
	}

	int nr = r - forward[d][0];
	int nc = c - forward[d][1];
	if (data[nr][nc] == 0) {
		return back(nr, nc, d, cnt);
	}
	else {
		return cnt;
	}

}

int main(void) {
	int N, M;
	int r, c, d;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	// d = 0 -> 북
	//     1 -> 동
	//     2 -> 남
	//     3 -> 서

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			scanf("%d", &data[i][j]);
		}
	}

	visited[r][c] = 1;
	printf("%d", back(r, c, d, 1));

	return 0;
}