// 1:00 시간초과
// 1:08 Accepted .... 단순 시뮬레이션으로 backtracking을 하니 시간초과
// 프루닝을 하니 억셉 나옴 
// 프루닝 : 1. 사다리를 하나 추가할때마다 한쌍이 더 개선될 수 있음. 따라서 개선되어야할 남은 쌍의 개수 > 남은 횟수 인 경우 return
//          2. 여지껏 구한 min보다 더 depth가 커지면 return

// 1~2번까지만해도 억셉.... 하나 추가해보자. 3. 사다리를 추가했을 때 개선이 되지 않는 경우에는 return    <- 오류있는듯..
// 또하나 추가                               4. 사다리를 놓을 공간이 바로 윗칸에도 있으면 return (중복 제거) <- 이건 틀림
//..... 조합 중복 처리 추가.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N, H, M;
int table[300][20];
int min = INF;

int goal(int s) {
	int y, x;
	y = 1; x = s;
	for (int y = 1;y <= H;y++) {
		if (table[y][x] == 1) x++;
		else if (table[y][x] == -1) x--;
	}
	return x;
}

int check() { // 짝이 다른것의 개수 출력
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (i != goal(i)) {
			cnt++;
		}
	}

	return cnt;
}

void back(int cnt, int ercnt, int row) {
	if (min < cnt) return;
	if (cnt <= 3) {
		int t;
		if ((t = check()) == 0) {
			if (min > cnt) {
				min = cnt;
			}
		}
		if (t > (3 - cnt)*2) return;


		for (int i = row;i <= H;i++) {			// 같은 행부터
			for (int j = 1;j <= N - 1;j++) {
				if (table[i][j] == 0 && table[i][j+1] == 0) {
					table[i][j] = 1; table[i][j + 1] = -1;
					back(cnt + 1, t, i);
					table[i][j] = table[i][j + 1] = 0;
				}
			}
		}

	}
	else return;
}

int main(void) {
	int a, b;
	scanf("%d %d %d", &N, &M, &H);
	
	for (int i = 1;i <= M;i++) {
		scanf("%d %d", &a, &b);
		table[a][b] = 1;
		table[a][b + 1] = -1;
	}

	back(0, INF, 1);																										

	if (min == INF) {
		printf("-1");
	}
	else printf("%d", min);
	return 0;
}