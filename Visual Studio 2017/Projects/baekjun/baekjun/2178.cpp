// 2차원 그리드 선상에서의 BFS => 굳이 Priority Queue를 사용할 필요가 없다.
// 유류 속도가 모두 1로 동일하기 때문

// 시간 : 11분


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int data[110][110];
int table[110][110];

int main(void) {
	int n, m;
	char line[110];
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &line[1]);		// fscanf(stdin, "%1d", &ch); <- 이렇게 하면 하나만 받아진다.
		int len = strlen(&line[1]);
		for (int j = 1;j <= len;j++) {
			data[i][j] = line[j]-'0';
		}
	}

	int queue[11000][3];
	int head, tail;
	head = 0, tail = 1;
	queue[0][0] = 1; // y
	queue[0][1] = 1; // x
	queue[0][2] = 1; // 1의 개수
	table[1][1] = 1;
	int dir[4][2] = { {0, 1}, {1, 0 }, {0, -1}, {-1, 0} };
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			int ny = queue[head][0] + dir[i][0];
			int nx = queue[head][1] + dir[i][1];
			if (table[ny][nx] == 0 && data[ny][nx] == 1) {
				table[ny][nx] = queue[head][2] + 1;
				queue[tail][0] = ny;
				queue[tail][1] = nx;
				queue[tail][2] = queue[head][2] + 1;
				tail++;
			}
		}
		head++;
	}

	fprintf(stdout, "%d", table[n][m]);
	return 0;
}