// 52
// bfs의 while 조건문에 head <= tail이라고 썼다가 이거 오류 찾느라 30분을 날렸다.
// 아니 왜.... 왜 =을 붙였나?? 미치는 것도 곱게 미쳐야지... 갑자기 당연히 알던것도 병신같이 하는 일이 생긴다.
// 이런 경우를 대비하기 위해서는 어떻게 해야하나...

// 1. 디버깅을 효율적으로 2. 평소에 캐쉬 
// 3. 범위를 한정지었으면... 이제 부터 내가 확실히 안다고 생각하는 것도 의심하기 시작해야한다. 아주 로우레벨 단계까지 코드 보면서 손디버깅해야한다. 
// 4. 아니면 바로 다른 기법으로 코딩해보는 것도..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int dat[9][9];
int map[9][9];

int count() { // 안전 영역의 수를 반환
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

void spread() { // 변경된 맵 데이터를 복사 받아서 바이러스를 퍼뜨린다.
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

int build() { // 벽을 세워서 시뮬레이션 후 max 값 반환
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