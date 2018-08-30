// 1:42
// 고친후 freopen 안없애 주면... 그냥 틀렸습니다 나올 수 있다...... *

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int K;
int L;
int apple[110][110];
int map[110][110];
int cmd[10010];
int dir[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };

int process() {
	int time = 0;
	int y, x;
	int dir_type = 0;
	int cnt = 0;
	y = x = 1;
	while (1) {
		y += dir[dir_type][0];
		x += dir[dir_type][1];
		cnt += apple[y][x]; 
		apple[y][x] = 0;
		time++;
		if (map[y][x] != -1) {
			// 경로 길이 / 뱀길이
			if (time - map[y][x] <= cnt + 1) break; // 이동 후 몸길이를 줄이기 때문에 =을 붙인다.
		}
		if (y > N || y < 1) break;
		if (x > N || x < 1) break;

		dir_type += cmd[time];
		if (dir_type == 4) dir_type = 0;
		else if (dir_type == -1) dir_type = 3;
//		dir_type = (dir_type + cmd[time]) % 4; // 여기...*********************************************************  틀린 포인트

		map[y][x] = time;
	}
	return time;
}

int main(void) {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 1;i <= K;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		apple[a][b] = 1;
	}
	scanf("%d", &L);
	for (int i = 1;i <= L;i++) {
		int a;
		char A[10];
		scanf("%d %s", &a, &A);

		if (A[0] == 'D') cmd[a] = 1;
		else cmd[a] = -1;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			map[i][j] = -1;
		}
	}
	map[1][1] = 0;



	printf("%d", process());
	return 0;
}

