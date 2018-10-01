// 59

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>


using namespace std;

int dir[5][2] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };


inline int abs(int a) {
	if (a < 0) return -a;
	return a;
}

struct Ap_info {
	int x, y;
	int c; // 반경
	int p; // 충전량
};

struct Pos {
	int y;
	int x;
};


int ap_cnt;
int move_time;
int dat[3][120];
Ap_info bc[10];
vector<int> list[3];

int process() {
	Pos cur[2];
	int sum = 0;

	cur[0].y = cur[0].x = 1;
	cur[1].y = cur[1].x = 10;
	for (int k = 0;k <= move_time;k++) { // 시간
		for (int i = 0;i <= 1;i++) { // 사용자
			cur[i].y += dir[dat[i][k]][0];
			cur[i].x += dir[dat[i][k]][1];
			list[i].clear();
			list[i].push_back(0);
			for (int j = 1;j <= ap_cnt;j++) {
				if (abs(bc[j].x - cur[i].x) + abs(bc[j].y - cur[i].y) <= bc[j].c) {
					list[i].push_back(j);
				}
			}
		}

		int max = 0;
		for (int t1 = 0;t1 < list[0].size();t1++) {
			for (int t2 = 0;t2 < list[1].size();t2++) {
				int temp;
				if (list[0][t1] == list[1][t2]) temp = bc[list[0][t1]].p;
				else temp = bc[list[0][t1]].p + bc[list[1][t2]].p;
				if (max < temp) {
					max = temp;
				}
			}
		}

		if (max != 0) {
			max = max;
		}
		sum += max;
	}
	return sum;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int tc = 1;tc <= T;tc++) {
		
		scanf("%d%d", &move_time, &ap_cnt);
		for (int j = 0;j <= 1;j++) {
			for (int i = 1;i <= move_time;i++) {
				scanf("%d", &dat[j][i]);
			}
		}

		for (int i = 1;i <= ap_cnt;i++) {
			scanf("%d%d%d%d", &bc[i].x, &bc[i].y, &bc[i].c, &bc[i].p);
		}

		printf("#%d %d\n", tc, process());
	}
	return 0;
}