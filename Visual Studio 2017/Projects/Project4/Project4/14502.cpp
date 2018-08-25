// 52
// bfs�� while ���ǹ��� head <= tail�̶�� ��ٰ� �̰� ���� ã���� 30���� ���ȴ�.
// �ƴ� ��.... �� =�� �ٿ���?? ��ġ�� �͵� ���� ���ľ���... ���ڱ� �翬�� �˴��͵� ���Ű��� �ϴ� ���� �����.
// �̷� ��츦 ����ϱ� ���ؼ��� ��� �ؾ��ϳ�...

// 1. ������� ȿ�������� 2. ��ҿ� ĳ�� 
// 3. ������ ������������... ���� ���� ���� Ȯ���� �ȴٰ� �����ϴ� �͵� �ǽ��ϱ� �����ؾ��Ѵ�. ���� �ο췹�� �ܰ���� �ڵ� ���鼭 �յ�����ؾ��Ѵ�. 
// 4. �ƴϸ� �ٷ� �ٸ� ������� �ڵ��غ��� �͵�..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int dat[9][9];
int map[9][9];

int count() { // ���� ������ ���� ��ȯ
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

int queue[100][2];
int dir[4][2] = { {0,1}, {1, 0}, {-1, 0}, {0, -1} };

void spread() { // ����� �� �����͸� ���� �޾Ƽ� ���̷����� �۶߸���.
	int head = 0, tail = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			map[i][j] = dat[i][j];
			if (map[i][j] == 2) {
				queue[tail][0] = i; // y
				queue[tail][1] = j; // x
				tail++;
			}
		}
	}

	int ny, nx;
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			ny = queue[head][0] + dir[i][0];
			nx = queue[head][1] + dir[i][1];
			if (ny > n || ny < 1) continue;
			if (nx > m || nx < 1) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = 2;
				queue[tail][0] = ny;
				queue[tail][1] = nx;
				tail++;
			}
		}
		head++;
	}
}

int build() { // ���� ������ �ùķ��̼� �� max �� ��ȯ
	int max = 0;
	for (int i = 1;i <= n*m;i++) {
		int y = (i - 1) / m + 1;
		int x = (i - 1) % m + 1;
		if (dat[y][x] != 0) continue;
		dat[y][x] = 1;
		for (int j = i+1;j <= n*m;j++) {
			int y = (j - 1) / m + 1;
			int x = (j - 1) % m + 1;
			if (dat[y][x] != 0) continue;
			dat[y][x] = 1;
			for (int k = j+1;k <= n*m;k++) {
				int y = (k - 1) / m + 1;
				int x = (k - 1) % m + 1;
				if (dat[y][x] != 0) continue;
				dat[y][x] = 1;
				spread();
				int cnt = count();
				if (max < cnt)
					max = cnt;
				dat[y][x] = 0;
			}
			dat[y][x] = 0;
		}
		dat[y][x] = 0;
	}
	return max;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			scanf("%d", &dat[i][j]);
		}
	}

	printf("%d", build());
	return 0;
}