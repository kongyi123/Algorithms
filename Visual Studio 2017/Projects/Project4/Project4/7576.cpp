#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[1001][1001];
int visited[1001][1001];
int queue[1000010][3];

int M, N;

int process() {
	int head = 0, tail = 0;

	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (data[i][j] == 1) {
				queue[tail][0] = j;
				queue[tail][1] = i;
				tail++;
				cnt++;
			}
			else if (data[i][j] == -1) cnt++;
		}
	}

	int max = 0;
	int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			int nx = queue[head][0] + dir[i][0];
			int ny = queue[head][1] + dir[i][1];
			if (nx < 1 || nx > M) continue;
			if (ny < 1 || ny > N) continue;
			if (visited[ny][nx] == 0 && data[ny][nx] == 0) {
				queue[tail][0] = nx;
				queue[tail][1] = ny;
				queue[tail][2] = queue[head][2] + 1;
				if (max < queue[tail][2]) max = queue[tail][2];
				tail++;
				visited[ny][nx] = 1;
				cnt++;
			}
		}
		head++;
	}

	if (cnt != N*M) return -1;
	return max;
}

int main(void) {
	scanf("%d %d", &M, &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			scanf("%d", &data[i][j]);
		}
	}

	printf("%d\n", process());
	return 0;
}